#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>

int dp[1 << 13];
int vis[1 << 13];
int id = 1;

int dope(int mask)
{
    if (vis[mask] == id)return dp[mask];
    else vis[mask] = id;
    int &ret = dp[mask];
    ret = __builtin_popcount(mask);

    for (int i = 0; i < 10; i++)
    {
        if ((mask & (1 << i) && mask & (1 << (i + 1)) && !(mask & (1 << (i + 2))))
            || (!(mask & (1 << i)) && mask & (1 << (i + 1)) && mask & (1 << (i + 2))))
        {
            ret = min(ret, dope(mask ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i + 2))));
        }
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    auto start = chrono::high_resolution_clock::now();
    while (n--)
    {
        string x;
        cin >> x;
        int mask{};
        for (int i = 0; i < 12; i++)
        {
            if (x[i] == 'o')
                mask |= (1 << i);
        }
        id++;
        cout << dope(mask) << endl;
    }
// code
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "Time taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}