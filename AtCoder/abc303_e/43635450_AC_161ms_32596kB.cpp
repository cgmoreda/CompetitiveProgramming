#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<ll,int>

vector<set<int>> G;
vi vis;
vi out;
queue<int> centers;

void dfs(int node)
{
    if (vis[node])return;
    out.push_back(G[node].size());
    vis[node] = 1;
    vector<int> conector;
    for (auto u: G[node])
    {
        vis[u] = 1;
        if (G[u].size() == 2)
            conector.push_back(u);
    }
    for (auto u: conector)
    {
        for (auto v: G[u])
        {
            if (v != node)
                for (auto v2: G[v])
                    if (!vis[v2])
                        centers.push(v2);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    G = vector<set<int>>(n + 1);
    vis = vi(n + 1);
    for (int u, v, i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (G[i].size() == 1)
        {
            dfs(*G[i].begin());
            break;
        }
    }
    while (!centers.empty())
    {
        dfs(centers.front());
        centers.pop();
    }
    sort(all(out));
    for (auto i: out)cout << i << " ";
    cout << endl;
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