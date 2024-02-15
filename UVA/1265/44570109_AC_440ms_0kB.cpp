#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
map<pair<int, int>, int> mp;

int get(int i, int j)
{
    if (mp.count({i, j}))
        return mp[{i, j}];
    if (mp.count({j, i}))
        return mp[{j, i}];
    return 1e9;
}

class DSU
{
public:
    vi p, sz, mn;
    vector<set<int>> s;
    vector<multiset<int>> ms;

    DSU(int N)
    {
        sz.assign(N + 1, 1);
        p.assign(N + 1, 0);
        mn.assign(N + 1, INT_MAX);
        ms = vector<multiset<int>>(N + 1);
        s = vector<set<int>>(N + 1);
        for (int i = 0; i <= N; i++)
            p[i] = i, s[i].insert(i);
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    int join(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (s[x].size() < s[y].size())
                swap(x, y);

            for (auto i: s[y])
                for (auto j: s[x])
                {
                    mn[x] = min(mn[x], get(i, j));
                    if (get(i, j) < 1e7)
                        ms[x].erase(ms[x].find(get(i, j))),
                                ms[y].erase(ms[y].find(get(i, j)));
                }
            ms[x].insert(all(ms[y]));
            s[x].insert(all(s[y]));
            p[y] = x;
            if (ms[x].empty() || *ms[x].rbegin() < mn[x])
                return s[x].size();
        }
        return 0;
    }

    void inpu(int u, int v)
    {
        ms[u].insert(v);
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
        return w != a.w ? w > a.w : u != a.u ? u < a.u : v < a.v;
    }
};

void solve()
{
    mp.clear();
    int n, m;
    cin >> n >> m;
    vector<edge> oj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        oj.push_back({u, v, w});
        mp[{u, v}] = w;
    }
    DSU ds(n);
    sort(all(oj));
    for (auto i: oj)
        ds.inpu(i.u, i.w), ds.inpu(i.v, i.w);
    ll ans = 0;
    for (int i = 0, j = 0; i < oj.size(); i++)
    {
        edge &e = oj[i];
        if (!ds.isSameSet(e.u, e.v))
            ans += ds.join(e.u, e.v);

    }
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