#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<ll,int>
#define iii tuple<int,int,int>
vector<ll> ds;
vector<vector<ii>> G, G2;
int n, m;
const int N = 2e5 + 20;
int id = 1;
int dp[N];
int vis[N];
const int mod = 1e9 + 7;

int dope(int i)
{
    if (i == 1)return 1;
    int &ret = dp[i];
    if (vis[i] == id)
        return ret;
    vis[i] = id;
    ll ret1 = 0;
    for (auto g: G2[i])
    {
        if (ds[i] - g.second == ds[g.first])
            ret1 += dope(g.first);
    }
    return ret = (int) (ret1 % mod);
}

int dfs(int i)
{
    if (i == 1)return 0;
    int &ret = dp[i];
    if (vis[i] == id)
        return ret;
    vis[i] = id;
    ret = 0;
    for (auto g: G2[i])
    {
        if (ds[i] - g.second == ds[g.first])
            ret = max(ret, dfs(g.first) + 1);
    }
    return ret;
}

int dfs2(int i)
{
    if (i == 1)return 0;
    int &ret = dp[i];
    if (vis[i] == id)
        return ret;
    vis[i] = id;
    ret = n;
    for (auto g: G2[i])
    {
        if (ds[i] - g.second == ds[g.first])
            ret = min(ret, dfs2(g.first) + 1);
    }
    return ret;
}


void solve()
{
    cin >> n >> m;
    G = vector<vector<ii>>(n + 1);
    G2 = vector<vector<ii>>(n + 1);

    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G2[b].push_back({a, c});
    }

    ds = vector<ll>(n + 1, 1e18);
    priority_queue<ii, vector<ii >, greater<ii>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int node = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if (dis >= ds[node])
            continue;
        ds[node] = dis;
        if (node == n)
            break;
        for (auto g: G[node])
        {
            if (dis + g.second < ds[g.first])
                pq.push({dis + g.second, g.first});
        }
    }

    cout << ds[n];

    cout << " " << dope(n);
    id++;
    cout << " " << dfs2(n);
    id++;
    cout << " " << dfs(n) << endl;
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