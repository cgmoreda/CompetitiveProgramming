#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<ii>>
#define ii pair<int,int>

class DSU
{
private:
    vi p, rank;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        for (int i = 0; i <= N; i++)
            p[i] = i;
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void join(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            } else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

};

struct edge
{
    int u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

vvi G;
ll n, m;
int c, d, t;
vi vis;

int dfs(int node)
{
    if (vis[node])
        return -1;
    vis[node] = 1;

    int ret = -1;

    for (auto u: G[node])
    {
        if (u.first == d)
            ret = max(ret, u.second);
        int tmp = dfs(u.first);
        if (tmp > 0)
        {
            ret = max(ret, min(tmp, u.second));
        }
    }
    return ret;
}

void solve()
{
    vector <edge> oj(m);
    for (auto &i: oj)
        cin >> i.u >> i.v >> i.w;
    sort(rall(oj), comp);
    DSU ds(n + 1);
    vis = vi(n + 1);
    G = vvi(n + 1);
    for (auto i: oj)
    {
        if (!ds.isSameSet(i.u, i.v))
        {
            ds.join(i.u, i.v);
            G[i.u].push_back({i.v, i.w});
            G[i.v].push_back({i.u, i.w});
        }
    }
    cin >> c >> d >> t;
    int mn = dfs(c) - 1;
    cout << (t + mn - 1) / mn << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, z = 0;
    //cin >> t;
    while (cin >> n >> m && n)
    {

        cout << "Scenario #" << ++z << "\n";
        cout << "Minimum Number of Trips = ";
        solve();
        cout << endl;
    }

}