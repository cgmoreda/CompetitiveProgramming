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
int n;
int oo = 2e5 + 1;

int dijkstra(int from, int to) {
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0, from});
    vector<int> dis(n + 1, oo);
    while (!pq.empty()) {
        int ds = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (to == node)return ds;
        if (dis[node] > ds && ds < oo) {
            dis[node] = ds;

            for (auto v: G[node]) {
                if (ds + v.second < dis[v.first]) {
                    pq.push({dis[node] + v.second, v.first});
                }
            }
        }
    }
}

void solve() {

    cin >> n;
    G = vector<vector<pair<int, int>>>(n + 1);
    map<string, int> ID_of;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        ID_of[name] = i;
        int p;
        cin >> p;
        while (p--) {
            int v, cost;
            cin >> v >> cost;
            G[i].push_back({v, cost});
        }
    }
    int r;
    cin >> r;
    while (r--) {
        string from, to;
        cin >> from >> to;
        cout << dijkstra(ID_of[from], ID_of[to]) << endl;
    }


}


int main() {


    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << fixed << setprecision(9);
    cerr << endl << "Time taken : " << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;

}