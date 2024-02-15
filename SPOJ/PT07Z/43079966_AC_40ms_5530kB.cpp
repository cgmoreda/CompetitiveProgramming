#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi G;
vi vis, val;
const int N = 1e5 + 10;
int dp[N];
int n;

void dfs(int node = 0, int dis = 0) {

    if (vis[node])return;
    vis[node] = true;
    val[node] = dis;
    for (auto u: G[node]) {
        dfs(u, dis + 1);
    }
}

void solve() {
    cin >> n;
    G = vvi (n + 1);
    vis = vi(n + 1);
    val = vi(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    dfs(1);
    int mx = *max_element(all(val));
    for (int i = 1; i <= n; i++) {
        if (val[i] == mx) {
            val = vi(n + 1);
            vis = vi(n + 1);
            dfs(i);
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
    //cin >> t;
    while (t--) {
        solve();;
    }

}