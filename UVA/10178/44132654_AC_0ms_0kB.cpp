#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

int n, m;


class DSU
{
private:
    vi p, rank, sz;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        sz = vi(N + 1, 1);
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
            sz[x] = sz[y] = sz[x] + sz[y];
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

    int getsz(int i)
    {
        return sz[findSet(i)];
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
    DSU ds(150);
    vector<pair<char, char>> ed(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ed[i].first >> ed[i].second;
        ds.join(ed[i].first, ed[i].second);
    }
    ll out = 1;
    map<int, int> ans;
    //m - (n - 1)
    for (auto i: ed)
    {
        ans[ds.findSet(i.first)]++;
    }
    for (auto i: ans)
    {
        int tn = ds.getsz(i.first) - 1;
        int tm = i.second;
        out += max(0, tm - tn);
    }
    cout << out << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m && n)
    {
        solve();;
    }

}