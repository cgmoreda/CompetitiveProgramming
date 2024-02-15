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

bool equals(edge a, edge b)
{
    if (a.u < a.v)swap(a.u, a.v);
    if (b.u < b.v)swap(b.u, b.v);
    return a.w == b.w && a.u == b.u && a.v == b.v;
}

void solve()
{
    vector<edge> edges;
    edge e;
    for (int i = 0; i < m; i++)
    {
        cin >> e.u >> e.v >> e.w;
        edges.emplace_back(e);
    }
    sort(all(edges),comp);
    DSU ds1(n + 1);
    vector<edge> MST;
    int mn = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        e = edges[i];
        if (!ds1.isSameSet(e.u, e.v))
        {
            ds1.unionSet(e.u, e.v);
            MST.push_back(e);
            mn += e.w;
        }
    }
    if (MST.size() != n - 1)
    {
        cout << "No way\n";
        return;
    }
    bool ok = false;
    int ndmn = 1e9;
    sort(all(edges), comp);
    for (int Rm = 0; Rm < MST.size(); Rm++)
    {
        int tmp = 0, cnt = 0;
        DSU ds(n + 1);
        int f1 = false;
        for (int i = 0; i < edges.size(); i++)
        {
            if (!f1 && equals(edges[i], MST[Rm]))
            {
                f1 = true;
                continue;
            }
            e = edges[i];
            if (!ds.isSameSet(e.u, e.v))
            {
                ds.unionSet(e.u, e.v);
                tmp += e.w;
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            ndmn = min(tmp, ndmn);
        }
    }
    if (ndmn > 9e8)
        cout << "No second way" << endl;
    else cout << ndmn << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, z = 1;
    cin >> t;

    while (t-- && cin >> n >> m && n)
    {
        cout << "Case #" << z++ << " : ";
        solve();
    }

}