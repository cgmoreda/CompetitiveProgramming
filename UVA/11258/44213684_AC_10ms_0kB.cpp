#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int N = 200 + 20;
ll dp[N];
int vis[N];
int id;
int n;
string x;
ll OO = 1e18;

ll dope(int i)
{
    if (i == n)
        return 0;

    ll &ret = dp[i];
    if (vis[i] == id)
        return ret;
    vis[i] = id;
    if (x[i] == '0')
        return ret = dope(i + 1);
    ret = -OO;
    ll sum = 0;
    for (int j = i; j < n; j++)
    {
        sum *= 10;
        sum += x[j] - '0';
        if (sum > INT_MAX)
            break;
        ret = max(ret, sum + dope(j+1));
    }
    return ret;
}

void solve()
{
    id++;
    cin >> x;
    n = x.size();
    cout << dope(0) << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();

    }

}