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
    int u, v, w;

    bool operator==(edge a) const
    {
        return this->u == a.u && this->v == a.v && this->w == a.w;
    }

    bool operator<(edge a) const
    {
        return this->w < a.w;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU ds(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.join(u, v);
    }
    int k;
    cin >> k;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u = ds.findSet(u);
        v = ds.findSet(v);
        if (u > v)
            swap(u, v);
        mp[{u, v}]++;
    }
    int q;
    cin >> q;

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u = ds.findSet(u);
        v = ds.findSet(v);
        if (u > v)
            swap(u, v);
        if (mp.count({u, v}))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
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