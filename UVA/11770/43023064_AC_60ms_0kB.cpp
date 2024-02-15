#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
 //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define mxval 10010
vvi G;
int n;
int id;
int ids[10010], low[10010];
bool onstack[10010];
stack<int> st;
int cnt;

void dfs(int at) {
    st.push(at);
    onstack[at] = true;
    ids[at] = low[at] = id++;

    for (auto to: G[at]) {
        if (!ids[to])
            dfs(to);
        if (onstack[to])
            low[at] = min(low[at], low[to]);
    }

    if (ids[at] == low[at]) {
        while (!st.empty()) {
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
    id = 1;
    cnt = 0;
    memset(ids, 0, sizeof(ids));
    for (int i = 1; i <= n; i++) {
        if (!ids[i])
            dfs(i);
    }
}

void solve() {

    int m;
    cin >> n >> m;
    G = vvi(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    int out = 0;
    scc();
    int inscc[10010] = {};
    for (int i = 1; i <= n; i++) {
        for (auto to: G[i]) {
            if (low[i] != low[to]) {
                inscc[low[to]]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ids[i] == low[i] && inscc[ids[i]] == 0)
            out++;
    }
    cout << out << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1,z=0;
    cin >> t;
    while (t--) {
        cout<<"Case "<<++z<<": ";
        solve();
    }

}