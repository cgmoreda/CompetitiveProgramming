#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vector<vector<ii>> G;
int n, m, T;
int oo = 1e9;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dijkstra(int st) {

    priority_queue<ii, vector<ii >, greater<ii > > pq;
    pq.push({0, st});
    vi dis(n + 1, oo);
    while (pq.size()) {
        int ds = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (ds < dis[node]) {
            dis[node] = ds;
            for (auto u: G[node])
                if (dis[u.first] > ds + u.second) {
                    pq.push({ds + u.second, u.first});
                }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret += (dis[i] <= T);
    return ret;
}


void solve() {
    int e;
    cin >> n >> e >> T >> m;
    G = vector<vector<ii>>(n + 1);
    map<pair<int, int>, int> mnfor;
    for (int i = 0; i < m; i++) {

        int a, b, t;
        cin >> a >> b >> t;
        if (mnfor.count({a, b}))
            mnfor[{a, b}] = min(mnfor[{a, b}], t);
        else mnfor[{a, b}] = t;
    }
    for (auto i: mnfor) {
        int from, to, cost;
        to = i.first.first;
        from = i.first.second;
        cost = i.second;
        G[from].push_back({to, cost});
    }

    cout << dijkstra(e) << endl;


}


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, z = 0;
    cin >> t;
    while (t--) {
        if (z++)cout << endl;
        //cout << "Case #" << ++z << ": ";
        solve();
    }


}