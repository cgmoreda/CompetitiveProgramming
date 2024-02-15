#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define vi vector<int>

vvi v;
bool vis[150];

void dfs(int node) {
    if (vis[node])return;

    vis[node] = true;

    for (auto u: v[node]) {
        dfs(u);
    }

}

void solve() {

    string x;
    v.clear();
    v = vvi(150, vi());
    memset(vis, 0, sizeof(vis));
    while (true) {
        getline(cin, x);
        if (x[0] == '*') {
            break;
        } else {
            int u = x[1], w = x[3];
            v[u].push_back(w);
            v[w].push_back(u);
        }
    }
    string y;
    getline(cin, y);

    set<char> s;
    for (auto i: y) {
        if (i != ',')
            s.insert(i);
    }
    int ac = 0, tr = 0;
    for (auto i: s) {
        if (!vis[i]) {
            if (v[i].empty()) {
                ac++;
            } else {
                tr++;
                dfs(i);
            }
        }
    }
    cout << "There are " << tr << " tree(s) and " << ac << " acorn(s).\n";

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