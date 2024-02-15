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
int n, m, s, t;
vector<vector<tuple<int, int, int>>> paths;
vi prv;

void printpath(int node) {

    if (node == s) {
        cout << s << " ";
        return;
    }
    printpath(prv[node]);
    cout << node;
    if (node != t)cout << " ";
    
}

class compare {
public:
    bool operator()(pair<ii, int> b, pair<ii, int> a) {
        if (a.first.first == b.first.first) {
            if (a.first.second == b.first.second) {
                return a.second < b.second;
            }
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
};

void solve() {

    cin >> s >> t;
    paths = vector<vector<tuple<int, int, int>>>(n + 1);
    for (int x, y, r, d, i = 0; i < m; i++) {
        char p;
        cin >> x >> y;
        int a, b;
        cin >> a >> p >> b;
        r = a * 10 + b;
        cin >> a >> p >> b;
        d = a * 10 + b;
        paths[x].push_back({y, r, d});
        paths[y].push_back({x, r, d});
    }

    priority_queue<ii, vector<ii >, greater<ii>> pq;
    pq.push({0, s});
    float mxt = 0, mxd = 0;
    map<pair<int, int>, int> vis;
    while (!pq.empty()) {
        int node, cmx;
        node = pq.top().second;
        cmx = pq.top().first;
        pq.pop();
        if (node == t) {
            mxt = cmx;
            break;
        }
        if (vis[{node, cmx}]++)continue;
        for (auto u: paths[node])
            pq.push({max(cmx, get<1>(u)), get<0>(u)});

    }
    while (!pq.empty())pq.pop();
    priority_queue<pair<ii, int>, vector<pair<ii, int> >, compare> pq2;

    pq2.push({{0, s}, s});
    prv = vi(n + 1, s);
    vi dis(n + 1, 1e9);
    vis.clear();
    while (!pq2.empty()) {
        int node, ds, pr;
        node = pq2.top().first.second;
        ds = pq2.top().first.first;
        pr = pq2.top().second;
        pq2.pop();
        if (dis[node] < ds)continue;
        prv[node] = pr;
        dis[node] = ds;
        for (auto u: paths[node])
            if (get<1>(u) <= mxt && dis[get<0>(u)] > ds + get<2>(u)) {
                pq2.push({{ds + get<2>(u), get<0>(u)}, node});
            }
    }
    mxd = dis[t];

    printpath(t);
    cout << fixed << setprecision(1) << endl;
    cout << mxd / 10 << " " << mxt / 10 << endl;
}


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, z = 0;
    // cin >> t;
    while (cin >> n >> m) {
        solve();
    }


}