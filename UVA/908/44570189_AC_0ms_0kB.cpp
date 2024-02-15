#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>4

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

    void unionSet(int i, int j)
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

int n, m;

void solve()
{

    vector<edge> oj;
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        edge e{};
        cin >> e.u >> e.v >> e.w;
        oj.push_back(e);
        cnt1 += e.w;

    }
    int k;
    cin >> k;
    vector<edge> ok;
    for (int i = 0; i < k; i++)
    {
        edge e{};
        cin >> e.u >> e.v >> e.w;
        ok.push_back(e);
    }
    vector<edge> om;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        edge e{};
        cin >> e.u >> e.v >> e.w;
        ok.push_back(e);
    }
    sort(all(ok), comp);
    DSU ds(n + 1);
    for (int i = 0; i < ok.size(); i++)
    {
        edge e = ok[i];
        if (!ds.isSameSet(e.u, e.v))
        {
            ds.unionSet(e.u, e.v);
            cnt2 += e.w;
        }
    }
    cout << cnt1 << endl;
    cout << cnt2 << endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 0;
    //cin >> t;
    while (cin >> n)
    {
        if (z++)
            cout << endl;
        solve();
    }

}