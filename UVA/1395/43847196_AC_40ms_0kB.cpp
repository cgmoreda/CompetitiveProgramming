#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define all(v) v.begin(),v.end()
#define vi vector<int>


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

    void unionSet(int i, int j)
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


int n, m;
struct edge
{
    int u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

void solve()
{
    deque<edge> edges;
    edge e;
    for (int i = 0; i < m; i++)
    {
        cin >> e.u >> e.v >> e.w;
        edges.emplace_back(e);
    }
    int ans = 1e9;
    sort(all(edges), comp);
    while (!edges.empty())
    {
        int cnt = 0;
        DSU ds(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            e = edges[i];
            if (!ds.isSameSet(e.u, e.v))
            {
                ds.unionSet(e.u, e.v);
                cnt++;
                if (cnt == n - 1)
                {
                    ans = min(ans, e.w - edges.front().w);
                    break;
                }
            }
        }
        if (cnt != n - 1)
            break;
        edges.pop_front();
    }
    if (ans > 9e8)
        ans = -1;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> m && n)
    {
        solve();
    }

}