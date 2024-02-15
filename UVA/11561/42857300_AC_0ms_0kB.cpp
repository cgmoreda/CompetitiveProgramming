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
vvc grid;
vvi vis, safe;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dfs(int i, int j) {
    vis[i][j] = 1;

    int ret = (grid[i][j] == 'G');

    if (!safe[i][j])return (ret);

    for (int idx = 0; idx < 4; idx++) if (valid(i + dx[idx], j + dy[idx]) && vis[i + dx[idx]][j + dy[idx]] == 0) ret += dfs(i + dx[idx], j + dy[idx]);

    return ret;
}

void solve() {

    grid = vvc(n, vc(m));
    vis = vvi(n, vi(m));
    safe = vvi(n, vi(m, 1));

    for (auto &i: grid)
        for (auto &j: i)
            cin >> j;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'T') {
                for (int idx = 0; idx < 4; idx++) {
                    if (valid(i + dx[idx], j + dy[idx])) {
                        safe[i + dx[idx]][j + dy[idx]] = 0;
                    }
                }
            }
            if (grid[i][j] == '#') {
                vis[i][j] = 1;
            }
            if (grid[i][j] == 'P') {
                x = i;
                y = j;
            }
        }
    }
    cout << dfs(x, y) << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> m >> n) {
        solve();
    }

}