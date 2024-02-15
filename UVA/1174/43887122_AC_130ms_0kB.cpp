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
    int n, m;
    cin >> n >> m;
    map<string, int> tid;
    int id = 0;
    vector<edge> egs;
    for (int i = 0; i < m; i++)
    {
        int w;
        string x, y;
        cin >> x >> y >> w;
        if (!tid.count(x))
            tid[x] = id++;
        if (!tid.count(y))
            tid[y] = id++;
        egs.push_back({tid[x], tid[y], w});
    }
    sort(all(egs), comp);
    DSU ds(n + 1);
    ll cnt = 0;
    for (auto i: egs)
    {
        if (!ds.isSameSet(i.u, i.v))
        {
            ds.join(i.u, i.v);
            cnt += i.w;
        }
    }
    cout << cnt << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, z = 0;
    cin >> t;
    while (t--)
    {
        if (z++)
            cout << endl;
        solve();
    }

}