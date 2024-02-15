#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

class DSU
{ // OOP style
private:
    vi p, rank, sz;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        sz.assign(N + 1, 1);
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
                sz[x] += sz[y];
                sz[y] = 0;
                p[y] = x;
            } else
            {
                sz[y] += sz[x];
                sz[x] = 0;
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int sizeSet(int x)
    {
        return sz[findSet(x)];
    }


};

struct rd
{
    int u, v;
    double c;
};

bool comp(rd a, rd b)
{
    return a.c < b.c;
}

int n, m;

vector<ii > points;

inline int sq(int x)
{
    return x * x;
}

inline double dis(int i, int j)
{
    return sqrt(sq(points[i].first - points[j].first) + sq(points[i].second - points[j].second));
}

void solve()
{
    points.clear();
    vector<rd> edges;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)continue;
            rd e;
            e.u = i;
            e.v = j;
            e.c = dis(i, j);
            edges.push_back(e);
        }
    }
    m = edges.size();
    sort(all(edges), comp);
    DSU ds(n + 1);
    vector<string> ans;
    double mx = 0;
    for (int i = 0; i < m; i++)
    {
        rd e = edges[i];
        if (!ds.isSameSet(e.u, e.v))
        {
            ds.unionSet(e.u, e.v);
            mx = max(mx, e.c);
        }
        if (ds.isSameSet(0, 1))
        {
            cout << fixed << setprecision(3);
            cout << mx << endl << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1, z = 0;
    // cin >> t;
    while (cin >> n && n)
    {
        cout << "Scenario #" << ++z << "\n";
        cout << "Frog Distance = ";
        solve();
    }

}