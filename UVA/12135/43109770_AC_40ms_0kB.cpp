#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n, m;
int ans[1000000];
vi ops;

void bfs() {
    memset(ans, -1, sizeof(ans));
    queue<tuple<int, int>> q;
    q.push({0, 0});
    while (q.size()) {
        int cond = get<0>(q.front());
        int steps = get<1>(q.front());
        q.pop();
        if (~ans[cond])continue;
        ans[cond] = steps;
        for (int i = 0; i < m; i++)
            q.push({ops[i] ^ cond, steps + 1});
    }
}

void solve() {
    cin >> n >> m;
    ops = vi(m + 1);
    vi &cas = ops;
    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k;
        while (k--) {
            cin >> x;
            ops[i] |= (1 << x);
        }
    }
    bfs();
    int q;
    cin >> q;

    while (q--) {
        string x;
        cin >> x;
        int num = 0;
        reverse(all(x));
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1')
                num |= (1 << i);
        }
        cout << ans[num] << "\n";
    }
    cout<<"\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << z++ << ":" << '\n';
        solve();;;;
    }

}