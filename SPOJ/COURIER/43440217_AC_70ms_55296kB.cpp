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
#define iii tuple<int,int,int>

int fact(int x)
{
    return x == 1 ? x : x * (fact(x - 1));
}

long long dp[(1 << 16) + 1][101];
int n, m, home;
vector<vector<int>> g;
vector<pair<int, int>> od;

long long calc(int i, int last, int taken = 0)
{
    if (taken == (1 << od.size()) - 1)
   // if (i == od.size())
        return g[last][home];


    long long &ret = dp[taken][last];
    if (~ret)
        return dp[taken][last];

    ret = 1e16;
    for (int k = 0; k < od.size(); k++)
    {
        if ((taken & (1 << k)) == 0)
            ret = min(ret,
                      g[last][od[k].first] +
                      g[od[k].first][od[k].second] +
                      calc(i + 1, od[k].second, (taken | (1 << k))));
    }

    return ret;
}

void solve()
{

    cin >> n >> m >> home;
    g = vector<vector<int>>(n + 1, vi(n + 1, 1e9));

    for (int  u, v, d,i = 0; i < m; i++)
    {
        cin >> u >> v >> d;
        g[v][u] = g[u][v] = min(g[u][v], d);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)g[i][j] = 0;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int z;
    cin >> z;
    od.clear();
    for (int u, v, d, i = 0; i < z; i++)
    {
        cin >> u >> v >> d;
        while (d--)
            od.emplace_back(u, v);

    }
    memset(dp, -1, sizeof(dp));

    ll ans = calc(0, home);

    cout << ans << endl;

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