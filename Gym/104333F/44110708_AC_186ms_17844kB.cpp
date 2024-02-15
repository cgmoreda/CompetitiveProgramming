#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<short>>
#define ii pair<int,int>


class DSU
{
private:
    vi p, pv;
    vector<multiset<int>> ms;
public:
    DSU(int N)
    {
        p.assign(N + 1, 0);
        pv.assign(N + 1, 0);
        ms = vector<multiset<int>>(N + 1);
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

            if (ms[x].size() < ms[y].size())
                swap(x, y);

            for (auto el: ms[y])
                ms[x].insert(el);

            p[y] = x;
        }
    }

    void addv(int i, int val)
    {
        ms[findSet(i)].insert(val);
    }

    void remv(int i, int val)
    {
        ms[findSet(i)].erase(ms[findSet(i)].find(val));
    }

    int getv(int i)
    {
        return *ms[findSet(i)].rbegin();
    }
};


struct edge
{
    int u, v;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU ds(n + 1);
    vector<int> pv(n + 1), out, buildedge(m, 1);
    vector<vector<int>> qq;
    vector<edge> eg(m);
    int q, t, x, y;

    for (int i = 1; i <= n; i++)
        cin >> pv[i];

    for (int i = 0; i < m; i++)
        cin >> eg[i].u >> eg[i].v;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t >> x;
        if (t == 2)
        {
            cin >> y;
            qq.push_back({t, x, pv[x]});
            pv[x] = y;
        } else
            qq.push_back({t, x});

        if (t == 1)
            buildedge[x - 1] = 0;
    }


    for (int i = 0; i < m; i++)
        if (buildedge[i])
            ds.join(eg[i].u, eg[i].v);

    for (int i = 1; i <= n; i++)
        ds.addv(i, pv[i]);


    for (int i = q - 1; i >= 0; i--)
    {
        t = qq[i][0];
        x = qq[i][1];
        if (t == 1)
        {
            ds.join(eg[x-1].u, eg[x-1].v);
        } else if (t == 2)
        {
            y = qq[i][2];
            ds.addv(x, y);
            ds.remv(x, pv[x]);
            pv[x] = y;
        } else if (t == 3)
        {
            out.push_back(ds.getv(x));
        }
    }

    reverse(all(out));

    for (auto i: out)
        cout << i << endl;
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