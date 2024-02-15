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
int n, m;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && j < m && i < n;
}

int floodfill(int i, int j) {
    if (grid[i][j] == 'w')
        return 0;
    grid[i][j] = 'w';
    int ret = 1;
    for (int idx = 0; idx < 4; idx++) {
        int x, y;
        x = i + dx[idx];
        y = j + dy[idx]+m;
        y%=m;
        if (valid(x, y)) {
            ret += floodfill(x, y);
        }
    }
    return ret;

}

void print() {

}

void solve() {

    grid = vvc(n, vc(m));
    vis = vvi(n, vi(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    char c = grid[x][y];

    for (auto &i: grid)for (auto &j: i)
            j = (j == c) ? 'l' : 'w';

    floodfill(x, y);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'l') {
                ans = max(ans, floodfill(i, j));
            }
        }
    }
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m) {
        solve();;
    }

}