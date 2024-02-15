#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vector<vector<pair<int, int>>> G;
int n, m, s, t;
int oo = 1e9;

int dijkstra(int from, int to) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, from});
    vector<int> dis(n + 1, oo);
    while (!pq.empty()) {
        int ds = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (to == node)return ds;
        if (dis[node] > ds) {
            dis[node] = ds;

            for (auto v: G[node]) {
                if (ds + v.second < dis[v.first]) {
                    pq.push({dis[node] + v.second, v.first});
                }
            }
        }
    }
    return -1;
}

void solve() {

    cin >> n >> m >> s >> t;
    G = vector<vector<pair<int, int>>>(n + 1);
    map<pair<int, int>, int> cost;
    for (int i = 0; i < m; i++) {
        int u, v, cst;
        cin >> u >> v >> cst;
        if (u > v)swap(u, v);
        if (cost.count({u, v}))
            cost[{u, v}] = min(cost[{u, v}], cst);
        else cost[{u, v}] = cst;
    }
    for (auto edge: cost) {
        int u, v, cst;
        u = edge.first.first, v = edge.first.second, cst = edge.second;
        G[u].push_back({v, cst});
        G[v].push_back({u, cst});
    }

    int ans = dijkstra(s, t);
    if (~ans)
        cout << ans << endl;
    else cout << "unreachable" << endl;


}


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, z = 0;
    cin >> t;
    while (t--) {
        cout << "Case #" << ++z << ": ";
        solve();
    }


}