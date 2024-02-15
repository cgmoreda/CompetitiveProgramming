#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi RD, SW;

int r, d, s;

map<tuple<int, vi >, int> vis;
queue<tuple<int, vi, vi, int>> q;
bool found = false;

void print(vi &v) {
    cout << "The problem can be solved in " << v.size() << " steps:\n";
    vi sassy(r + 1);
    sassy[1] = 1;
    for (auto i: v) {
        if (i < 0) {
            int bulb = -i;
            if (!sassy[bulb])
                cout << "- Switch " << "on ";
            else
                cout << "- Switch " << "off ";
            sassy[bulb] ^= 1;
            cout << "light in room " << bulb << ".\n";
        } else {
            cout << "- Move to room " << i << ".\n";
        }
    }
    cout << flush;
}

void bfs() {
    if (found)return;
    int roomnumber = get<0>(q.front());
    vi state = get<1>(q.front());
    if (roomnumber == r && count(state.begin(), state.end() - 1, 1) == 0) {
        found = true;
        print(get<2>(q.front()));
        return;
    }
    if (vis.count({roomnumber, state})) {
        q.pop();
        if (!q.empty())bfs();
        return;
    }
    vis[{roomnumber, state}] = 1;
    vi ops = get<2>(q.front());
    int steps = get<3>(q.front());
    q.pop();
    for (auto swtch: SW[roomnumber]) {
        if (swtch != roomnumber) {
            state[swtch] ^= 1;
            ops.push_back(-swtch);
            if (!vis.count({roomnumber, state}))
                q.push({roomnumber, state, ops, steps + 1});
            state[swtch] ^= 1;
            ops.pop_back();
        }
    }
    for (auto u: RD[roomnumber]) {
        if (state[u]) {
            ops.push_back(u);
            if (!vis.count({u, state}))
                q.push({u, state, ops, steps + 1});
            ops.pop_back();
        }
    }
    if (!q.empty())bfs();
}

void solve() {
    RD = vvi(r + 1);
    SW = vvi(r + 1);
    for (int u, v, i = 0; i < d; i++) {
        cin >> u >> v;
        RD[u].push_back(v);
        RD[v].push_back(u);
    }
    for (int u, v, i = 0; i < s; i++) {
        cin >> u >> v;
        SW[u].push_back(v);
    }
    vis.clear();
    while (!q.empty())q.pop();
    found = false;
    vi state1(r + 1, 0);
    state1[1] = 1;
    q.push({1, state1, {}, 0});
    bfs();

    if (!found) {
        cout << "The problem cannot be solved.\n";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> r >> d >> s && (r + s + d)) {
        cout << "Villa #" << t++ << endl;
        solve();
        cout << endl;;
    }

}