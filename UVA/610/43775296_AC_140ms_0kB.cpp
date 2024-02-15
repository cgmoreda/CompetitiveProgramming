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
set<pair<int, int>> edge;
int n, m;
int z = 1;

void tarjan(int node)
{
    if (dnum[node] != -1)
        return;
    dnum[node] = dlow[node] = ++id;

    for (auto u: G[node])
    {
        if (dnum[u] == -1)
        {

            edge.insert({node, u});
            pr[u] = node;
            tarjan(u);
            if (dnum[node] < dlow[u])
            {
                 edge.insert({u, node});
            }
            dlow[node] = min(dlow[node], dlow[u]);

        } else if (u != pr[node])
        {
            if (edge.find({u, node}) == edge.end())
                edge.insert({node, u});
            dlow[node] = min(dlow[node], dnum[u]);
        }
    }


}

void solve()
{
    cout << z << endl << endl;
    id = 0;
    edge.clear();
    G = vvi(n + 1);
    dnum = vi(n + 1, -1);
    dlow = vi(n + 1);
    pr = vi(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    tarjan(1);
    for (auto i: edge)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "#\n";

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
