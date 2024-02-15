#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
string x;
vector<vector<tuple<int, int>>> G;
vi vis, val;

void dfs(int node, int dis) {
    if (vis[node])return;
    vis[node] = 1;
    val[node] = dis;

    for (auto u: G[node]) {
        dfs(get<0>(u), get<1>(u) + dis);
    }
}

void solve() {
    G = vector<vector<tuple<int, int>>>(10010);
    int u, v, d;
    do {
        vector<string> vec;
        string tmp;
        for (char i: x) {
            if (i == ' ') {
                vec.push_back(tmp);
                tmp = "";
            } else tmp += i;
        }
        if (!tmp.empty())
            vec.push_back(tmp);

        u = stoi(vec[0]);
        v = stoi(vec[1]);
        d = stoi(vec[2]);

        G[u].push_back({v, d});
        G[v].push_back({u, d});

        getline(cin, x);
    } while (!x.empty());

    vis = vi(10010);
    val = vi(10010);
    dfs(u, 0);
    int mx = *max_element(all(val));
    for (int i = 1; i < 10010; i++) {
        if (mx == val[i]) {
            vis = vi(10010);
            val = vi(10010);
            dfs(i, 0);
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
    while (getline(cin, x)) {
        solve();
    }

}