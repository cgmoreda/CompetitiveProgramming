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

struct rd
{
    int u;
    int wis;
    int cost;
};

vector<vector<rd>> G;
int n, m, k;

int dikstra(int x)
{
    priority_queue<ii, vector<ii >, greater<ii>> pq;
    pq.push({0, 1});
    vi vis(n + 1);
    vector<long long> dis(n + 1, 1e18);
    while (pq.size())
    {
        ll ds = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node] || ds > dis[node])continue;
        vis[node] = 1;
        dis[node] = ds;
        if (node == n)
        {
            return ds;
        }
        for (auto rode: G[node])
        {
            if (dis[rode.u] > ds + rode.cost && rode.wis <= x)
                pq.push({ds + rode.cost, rode.u});
        }
    }
    return -1;
}

void solve()
{
    cin >> n >> m >> k;
    G = vector<vector<rd>>(n + 1);
    for (int i = 0; i < m; i++)
    {
        rd r1;
        int v;
        cin >> v >> r1.u >> r1.cost >> r1.wis;
        G[v].push_back(r1);
        swap(r1.u, v);
        G[v].push_back(r1);
    }

    int l = 0, r = 1e9, mid, ans = 1e9;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll tmp = dikstra(mid);
        if (~tmp && tmp < k)
        {
            r = mid - 1;
            ans = min(ans, mid);
        } else l = mid + 1;
    }
    if (ans == 1e9)
    {
        cout << -1 << endl;
    } else cout << ans << endl;

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