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

    double w;

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

void solve()
{
    int n, m;
    cin >> n;
    vector<point> city;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        city.push_back({x, y});
    }
    DSU ds(n + 1);
    cin >> m;
    for (int i = 0, p1, p2; i < m; i++)
    {
        cin >> p1 >> p2;
        p1--, p2--;
        ds.join(p1, p2);
    }
    vector<edge> oj, out;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            oj.push_back({i, j, city[i].dis(city[j])});

    sort(all(oj));
    for (auto i: oj)
    {
        if (!ds.isSameSet(i.u, i.v))
        {
            ds.join(i.u, i.v);
            out.push_back(i);
        }
    }
    if (out.size() == 0)
    {
        cout << "No new highways need" << endl;
    }
    for (auto i: out)
    {
        cout << i.u + 1 << " " << i.v + 1 << endl;
    }

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