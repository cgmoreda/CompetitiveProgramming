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
int n, m;
vi ans, vis;

void dfs(int node)
{
    if(vis[node])return;
    vis[node]=1;
    for(auto u:G[node])
        dfs(u);
    ans.push_back(node);
}
void solve() {
    ans.clear();
    vis = vi(n + 1);
    G = vvi(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++)s.insert(i);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> v >> u;
        G[u].push_back(v);
        s.erase(v);
    }
    for (auto i: s) {
        dfs(i);
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m) {
        if (n + m == 0)break;
        solve();;
    }

}