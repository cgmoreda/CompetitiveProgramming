#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>
#define vvi vector<vector<ii>>


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

    bool operator==(edge a) const
    {
        return this->u == a.u && this->v == a.v && this->w == a.w;
    }

    bool operator<(edge a) const
    {
        return this->w < a.w;
    }
};


vvi G;

int minrol(string x, string y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int tmp = min(abs(x[i] - y[i]), 10 - abs(x[i] - y[i]));
        cnt += tmp;
    }
    return cnt;
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<edge> oj, op;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        oj.push_back({u, v, w});
    }
    sort(all(oj));
    DSU ds1(n + 1);
    int cost1 = 0;
    for (auto i: oj)
    {
        if (!ds1.isSameSet(i.u, i.v))
        {
            ds1.join(i.u, i.v);
            cost1 += i.w;
            op.push_back(i);
        }
    }
    int cost2 = 1e9;
    for (auto j: op)
    {
        bool f1 = true;
        DSU ds(n + 1);
        int tmpcost = 0;
        for (auto i: oj)
        {
            if (f1 && i == j)
            {
                f1 = false;
                continue;
            }
            if (!ds.isSameSet(i.u, i.v))
            {
                ds.join(i.u, i.v);
                tmpcost += i.w;
            }
        }
        set<int> s;
        for (int i = 1; i <= n; i++)
        {
            s.insert(ds.findSet(i));
        }
        if (s.size() == 1)
            cost2 = min(cost2, tmpcost);
    }
    cout << cost1 << " " << cost2 << endl;

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