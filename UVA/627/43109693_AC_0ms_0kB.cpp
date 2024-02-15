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
int vis[500];
int n, m;

void print(vi &v) {
    int z=0;
    for (auto i: v) {
        if (z++)cout << " ";
        cout << i;
    }
    cout << endl;
}

void bfs(int at, int to) {
    queue<vi > q;
    q.push({at});
    memset(vis, 0, sizeof(vis));
    int level = 0;
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {
            vector<int> cat = q.front();
            q.pop();
            if (vis[cat.back()] == 2) {
                continue;
            }
            if (cat.back() == to) {
                print(cat);
                return;
            }
            vis[cat.back()] = 1;

            for (auto u: G[cat.back()]) {
                if (!vis[u]) {
                    vis[u] = 1;
                    cat.push_back(u);
                    q.push(cat);
                    cat.pop_back();
                }
            }
        }
        level++;
    }
    cout << "connection impossible\n";
}

void solve() {

    G = vvi(n + 1);

    for (int u = 1; u <= n; u++) {
        string x;
        getline(cin, x);
        while (!x.empty() && x.back() == ' ')x.pop_back();
        if (x.empty()) {
            u--;
            continue;
        }
        int i = 0;
        while (x[i] != '-' && i < x.size()) i++;
        for (++i; i < x.size(); i++) {
            int v = 0;
            while (x[i] != ',' && i < x.size()) {
                v *= 10;
                v += x[i] - '0';
                i++;
            }
            G[u].push_back(v);
        }
    }

    int q;
    cin >> q;
    cout << "-----" << endl;
    while (q--) {
        int u, v;
        cin >> u >> v;
        bfs(u, v);
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n) {
        solve();
        cout << flush;
    }

}