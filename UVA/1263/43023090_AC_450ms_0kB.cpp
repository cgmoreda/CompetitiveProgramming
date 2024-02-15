#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define mxval 2020
vvi G;
int n;
int id;
int ids[mxval], low[mxval];
bool onstack[mxval];
stack<int> st;
int cnt;

void dfs(int at) {
    st.push(at);
    onstack[at] = true;
    ids[at] = low[at] = id++;

    for (auto to: G[at]) {
        if (!~ids[to])
            dfs(to);
        if (onstack[to])
            low[at] = min(low[at], low[to]);
    }

    if (ids[at] == low[at]) {
        while (true) {
            int nd = st.top();
            st.pop();
            onstack[nd] = false;
            low[nd] = low[at];
            if (nd == at)break;
        }
        cnt++;
    }
}

void scc() {
    id = 0;
    cnt = 0;
    memset(ids, -1, sizeof(ids));
    for (int i = 0; i < n; i++) {
        if (!~ids[i])
            dfs(i);
    }
}

void solve() {


    cin >> n;
    vector<vector<int>> inp(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> inp[i][0];
        cin >> inp[i][1];
        cin >> inp[i][2];
    }
    G.clear();
    G = vvi(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i != j) {
                int x1 = inp[i][0], y1 = inp[i][1], d = inp[i][2] / 2, x2 = inp[j][0], y2 = inp[j][1];
                if (abs(x1 - x2) <= d && abs(y1 - y2) <= d)
                    G[i].push_back(j);
            }
    }
    int out = 0;
    scc();
    int inscc[mxval] = {};
    for (int i = 0; i < n; i++) {
        for (auto to: G[i]) {
            if (low[i] != low[to]) {
                inscc[low[to]]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ids[i] == low[i] && inscc[ids[i]] == 0)out++;
    }
    //cout << "cnt " << cnt << endl;
    cout << out << endl;
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