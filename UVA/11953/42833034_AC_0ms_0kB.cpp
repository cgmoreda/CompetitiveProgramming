#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>


int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int n;
vvc grid, vis;

bool valid(int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= n);
}

void dfs(int i, int j) {
    if (!valid(i, j) || vis[i][j] == '!') return;
    vis[i][j] = '!';
    for (int idx = 0; idx < 4; idx++) {
        int x, y;
        x = i + dx[idx];
        y = j + dy[idx];
        if (valid(x, y) &&grid[x][y] != '.' &&vis[x][y] == '.') {
            dfs(x, y);
        }

    }

}

void solve() {
    cin >> n;
    grid = vvc(n, vc(n));
    vis = vvc(n, vc(n, '.'));

    for (auto &i: grid)for (auto &j: i)cin >> j;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'x' && vis[i][j] == '.')
                dfs(i, j), cnt++;

        }
    cout << cnt << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

}