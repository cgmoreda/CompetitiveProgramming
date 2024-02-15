#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define all1(v) v.begin()+1,v.end()
vector<vector<tuple<int, int>>> G;
int n;
vi vis;

int dfs(int node) {
    vis[node] = 1;
    int ret = 0;
    for (auto &u: G[node]) {
        if (vis[get<0>(u)] == 1)continue;

        get<1>(u) = dfs(get<0>(u));
        ret = max(get<1>(u), ret);
    }
    return ret + 1;

}

void dfs2(int node, int pr = 0) {
    vis[node] = 4;
    int mx = 0;
    for (auto u: G[pr]) {
        if (get<0>(u) == node)continue;
        mx = max(mx, get<1>(u));
    }
    for (int i = 0; i < G[node].size(); i++) {
        if (get<0>(G[node][i]) == pr)
            get<1>(G[node][i]) = mx + 1;
    }

    for (auto u: G[node]) {
        if (vis[get<0>(u)] == 4)continue;
        dfs2(get<0>(u), node);
    }

}

int maxv(vector<tuple<int, int>> &v) {
    int mx = 0;
    for (auto i: v) {
        mx = max(mx, get<1>(i));
    }
    return mx;
}

void solve() {
    G = vector<vector<tuple<int, int>>>(n + 1);

    int tmp, v;
    for (int u = 1; u <= n; u++) {
        cin >> tmp;
        while (tmp--) {
            cin >> v;
            G[u].push_back({v, -1});
        }
    }

    vis = vi(n + 1);

    dfs(1);
    dfs2(1);

    vi ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = maxv(G[i]);


    int mx = *max_element(all1(ans));
    int mn = *min_element(all1(ans));
    int f = 0;
    cout << "Best Roots  : ";
    for (int i = 1; i <= n; i++) {
        if (ans[i] == mn) {
            if (f++)cout << " ";
            cout << i;
        }
    }
    cout << endl;
    cout << "Worst Roots : ";
    f = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == mx) {
            if (f++)cout << " ";
            cout << i;
        }
    }
    cout << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     int t = 1;
    //cin >> t;
    while (cin >> n) {
        solve();
    }

}