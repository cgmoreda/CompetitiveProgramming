#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>
vi dnum, dlow, pr;
int id;
vvi G;
vvi mp;
int n, m;
int z = 1;


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

DSU ds(0);

void tarjan(int node)
{
    if (dnum[node] != -1)
        return;
    dnum[node] = dlow[node] = ++id;

    for (auto u: G[node])
    {
        if (dnum[u] == -1)
        {

            pr[u] = node;
            tarjan(u);
            if (dnum[node] < dlow[u])
            {
                ds.join(node, u);
            }
            dlow[node] = min(dlow[node], dlow[u]);

        } else if (u != pr[node])
        {
            dlow[node] = min(dlow[node], dnum[u]);
        }
    }


}


void solve()
{
    int q;
    cin >> q;
    id = 0;
    G = vvi(n + 1);
    mp = vvi(n + 1);
    dnum = vi(n + 1, -1);
    dlow = vi(n + 1);
    pr = vi(n + 1);
    ds = DSU(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        tarjan(i);


    while (q--)
    {
        int s, e;
        cin >> s >> e;
        if (ds.isSameSet(s, e))
            cout << "Y\n";
        else cout << "N\n";
    }
    cout << "-" <<
         endl;

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
        solve();
        z++;
    }

}
