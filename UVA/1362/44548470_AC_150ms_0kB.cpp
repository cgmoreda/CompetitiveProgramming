#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>


int n, m;
string x;
int dp[303][303];
int pvis[303][303];
int vis[303][303];
bool p[303][303];
int id;

const int mod = 1e9;

bool pal(int l, int r)
{
    bool &ret = p[l][r];
    if (pvis[l][r] == id)
        return ret;

    pvis[l][r] = id;

    if (l >= r)
        return ret = true;
    return ret = (x[l] == x[r] && pal(l + 1, r - 1));
}

int dope(int l, int r)
{
   
    if (l > r || x[l] != x[r])
        return 0;
    if (l == r)
        return 1;
    
    int &ret = dp[l][r];
    if (vis[l][r] == id)
        return ret;
    
    vis[l][r] = id;
    ll bk = 0;
    for (int i = l + 1; i <= r; i++)
        if (x[i] == x[l] && x[i] == x[r])
            bk += 1LL * dope(l + 1, i - 1) * dope(i, r) % mod;

    return ret = bk % mod;
}

void solve()
{
    n = x.size();
    id++;

    cout << dope(0, n - 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> x && x != "")
    {
        solve();;
    }

}
