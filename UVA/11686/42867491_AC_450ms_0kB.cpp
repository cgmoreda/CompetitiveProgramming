#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pair<int,int>>>
#define vpii vector<pair<int,int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n, m;
vvi G;
vi vis, col;
bool ok;

void checknotcyclic(int node) {

    if (vis[node] == 1) {
        ok = false;
        return;
    }
    if (vis[node] == 2)
        return;
    vis[node] = 1;
    for (auto u: G[node]) {
        checknotcyclic(u);
    }
    vis[node] = 2;
}

vi ans;

void dfs(int node) {
    if (vis[node])
        return;
    vis[node] = 1;
    for (auto u: G[node]) {
        dfs(u);
    }
    ans.push_back(node);
}

void solve() {

    G = vvi(n + 1);
    vis = vi(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    ok = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            checknotcyclic(i);
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vis = vi(n + 1);
    ans.clear();
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }
    reverse(all(ans));
    for (auto i: ans) {
        cout << i << "\n";
    }
    cout << flush;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m) {
        if (!(n + m))
            break;
        solve();
    }

}