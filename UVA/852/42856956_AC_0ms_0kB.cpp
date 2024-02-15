#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvc grid;
vvi vis;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < 9 && j < 9;
}


int check = 0;

int dfs(int i, int j, char sh) {
    if (vis[i][j] || grid[i][j] != sh) {
        if (sh == '.') {
            if (grid[i][j] == 'X')
                check |= 1;
            else if (grid[i][j] == 'O')
                check |= 2;
        }
        return 0;
    }
    vis[i][j] = 1;
    int ret = 1;
    for (int idx = 0; idx < 4; idx++) {
        int x, y;
        x = i + dx[idx];
        y = j + dy[idx];
        if (valid(x, y)) {
            ret += dfs(x, y, sh);
        }
    }
    return ret;
}

void solve() {

    grid = vvc(9, vc(9));
    vis = vvi(9, vi(9));
    for (auto &i: grid)
        for (auto &j: i)
            cin >> j;
    int black = 0;
    int white = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (vis[i][j])continue;
            if (grid[i][j] == 'X')
                black += dfs(i, j, 'X');
            if (grid[i][j] == 'O')
                white += dfs(i, j, 'O');
            else if (grid[i][j] == '.') {
                check = 0;
                int ans = dfs(i, j, '.');
                if (check == 1)
                    black += ans;
                if (check == 2)
                    white += ans;
            }
        }
    }
    cout << "Black " << black << " White " << white << endl;
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