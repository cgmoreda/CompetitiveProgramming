#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

int x, y;
vector<set<int>> G;
map<int, int> mp;
int id;

int g(int i)
{
    if (!mp.count(i))
        mp[i] = id++, G.emplace_back();

    return mp[i];
}

vi vis;

void dfs(int node)
{
    if (vis[node])
    {
        vis[node] = -1e4;
        return;
    }
    vis[node] = 1;
    for (auto i: G[node])
        dfs(i);
}

void solve()
{

    id = 0;
    mp.clear();
    G.clear();
    int u = g(x);
    int v = g(y);
    bool ok = u != v;
    G[u].insert(v);
    if (!(x && y))
    {
        cout << "is a tree.\n";
        return;
    }
    while (cin >> x >> y && x && y)
    {

        u = g(x);
        v = g(y);
        if (G[u].find(v) != G[u].end() || u == v)
            ok = false;
        G[u].insert(v);
    }
    int n = G.size();
    vi indeg(n);
    vis = vi(n);
    for (int i = 0; i < n; i++)
        for (auto j: G[i])
            indeg[j]++;

    if (ok && count(all(indeg), 1) == n - 1 && count(all(indeg), 0) == 1)
    {

        dfs(min_element(all(indeg)) - indeg.begin());
        if (count(all(vis), 1) == n)
            cout << "is a tree.\n";
        else
            cout << "is not a tree.\n";
    } else
        cout << "is not a tree.\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> x >> y && x >= 0)
    {
        cout << "Case " << t++ << " ";
        solve();
    }

}