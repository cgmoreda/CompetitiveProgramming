#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

#define all(v) v.begin(),v.end()
#define vi vector<int>


vector<vector<tuple<int, int>>> G;
vi vis, val;

void dfs(int node, int dis) {
    if (vis[node] == 1)return;
    vis[node] = 1;
    val[node] = dis;
    for (auto u: G[node]) {
        dfs(get<0>(u), dis + get<1>(u));
    }
}

void solve() {
    int n;
    cin >> n;
    G = vector<vector<tuple<int, int>>>(n + 1);
    int u, v, d;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> d;
        G[u].push_back({v, d});
        G[v].push_back({u, d});
    }

    vis = vi(n + 1);
    val = vi(n + 1);
    dfs(u, 0);
    int mx = *max_element(all(val));
    for (int i = 1; i < n; i++) {
        if (mx == val[i]) {
            vis = vi(n + 1);
            val = vi(n + 1);
            dfs(i, 0);
            cout << *max_element(all(val)) << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}