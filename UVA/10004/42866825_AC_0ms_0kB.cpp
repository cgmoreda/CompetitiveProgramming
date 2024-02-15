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

void dfs(int node, int clr = 0) {

    if (vis[node] == 1) {
        ok &= (col[node] == clr);
        return;
    }
    vis[node] = 1, col[node] = clr;

    for (auto u: G[node])
        dfs(u, clr ^ 1);
}

void solve() {

    G = vvi(n);
    vis = vi(n);
    col = vi(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ok = true;
    dfs(0);
    if (ok)
        cout << "BICOLORABLE.\n";
    else cout << "NOT BICOLORABLE.\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n) {
        if (!n)break;
        cin >> m;
        solve();
    }

}