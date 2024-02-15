#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
// count odd cycles
vvi superior, boss_of;
vi vis, ans;
int n;
int main_boss = 0;

void print(vi &v) {
    for (auto i: v)
        cout << i << " ";
    cout << endl;
}


void dfs(int node) {
    if (vis[node])return;
    vis[node] = true;

    for (auto u: superior[node]) {
        dfs(u);
    }
    ans.push_back(node);
}

void solve() {
    int k, u, v;
    cin >> n >> k;
    superior = vvi(n + 1);
    boss_of = vvi(n + 1);

    vis = vi(n + 1);

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        while (a--) {
            cin >> v;
            u = i + 1;
            superior[u].push_back(v);
            boss_of[v].push_back(u);
        }
    }

    for (int i = 1; i <= k; i++) {
        if (boss_of[i].size() == 0) {
            main_boss = i;
            break;
        }
    }
    dfs(main_boss);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    vi out(n + 2);
    ans.push_back(0);
    for (int i = 0; i < n; i++) {
        out[ans[i]] = ans[i+1];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<out[i]<<endl;
    }
   // print(ans);

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