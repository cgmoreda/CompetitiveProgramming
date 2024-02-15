#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
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

inline int sq(int x)
{
    return x * x;
}

struct point
{
    int x, y;

    double dis(point a) const
    {
        return sqrt(sq(x - a.x) + sq(y - a.y));
    }
};

struct edge
{
    int u, v;


};

bool comp(edge a, edge b)
{
    if (max(a.u, a.v) == max(b.u, b.v))
    {
        return min(a.u, a.v) < min(b.u, b.v);
    }
    return max(a.u, a.v) < max(b.u, b.v);
}

vvi G;

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    G = vvi(n + 1);
    DSU ds(n + 1);
    vector<edge> oj;
    for (int i = 0; i < m; i++)
    {
        edge a;
        cin >> a.u >> a.v;
        oj.push_back(a);
    }
    sort(all(oj), comp);
    for (auto i: oj)
    {
        if (!ds.isSameSet(i.u, i.v))
        {
            ds.join(i.u, i.v);
            G[i.v].push_back(i.u);
            G[i.u].push_back(i.v);
        }
    }
    int mn = 0;
    for (int i = 1; i <= n; i++)
    {
        mn = max(mn,(int) G[i].size());
    }
    cout << mn << endl;

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