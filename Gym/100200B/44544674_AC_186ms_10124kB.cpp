#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>
vi dnum, dlow, pr;
int id;
vvi G;
int n, m;
int z = 1;

map<ii, int> mp;
vector<int> edge;

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
                edge.push_back(mp[{min(node, u), max(node, u)}]);
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
    cin >> n >> m;
    id = 0;
    G = vvi(n + 1);
    dnum = vi(n + 1, -1);
    dlow = vi(n + 1);
    pr = vi(n + 1);
    edge.clear();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        if (mp.count({min(v, u), max(u, v)}))
            mp[{min(v, u), max(u, v)}] = -1;
        else
            mp[{min(v, u), max(u, v)}] = i + 1;
    }
    for (int i = 1; i <= n; i++)
        tarjan(i);

    sort(rall(edge));
    while (edge.size() && edge.back() == -1)
        edge.pop_back();
    sort(all(edge));
    cout << edge.size() << endl;
    for (auto i: edge)
        if (~i)
            cout << i << " ";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}
