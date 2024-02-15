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
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

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
    int n;
    cin >> n;
    vector<string> v;
    map<string, int> stid;
    int id = 0;
    v.push_back("0000");
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        stid[c] = id++;
        v.push_back(c);
    }
    G = vvi(n + 1);
    vector<edge> oj;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            oj.push_back({i, j, minrol(v[i], v[j])});
    sort(all(oj), comp);
    DSU ds(n + 2);
    int cost = 0;
    bool f1 = false;
    for (auto i: oj)
    {
        if (f1 && i.u == 0)
            continue;
        if (!ds.isSameSet(i.u, i.v))
        {
            ds.join(i.u, i.v);
            cost += i.w;
        }
        f1 |= i.u == 0;
    }
    cout << cost << endl;

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