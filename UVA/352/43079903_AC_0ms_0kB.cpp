#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n;
int t = 1;
vvc grid, vis;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void print(vvc &v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << j;
        }
        cout << endl;
    }
}

void dfs(int i, int j) {
    if (i == n || j == n || vis[i][j] == '1' || grid[i][j] == '0')return;
    vis[i][j] = '1';
    for (int idx = 0; idx < 8; idx++) {
        int x, y;
        x = i + dx[idx];
        y = j + dy[idx];
        if (x >= 0 && y >= 0)
            dfs(x, y);
    }

}

void solve() {
    grid = vvc(n, vc(n));
    vis = vvc(n, vc(n, '0'));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == '0' && grid[i][j] == '1') {
                dfs(i, j);
                cnt++;
                //print(vis);
            }
        }
    cout << "Image number " << t << " contains " << cnt << " war eagles." << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Bumble.in", "r", stdin);
    //freopen("Bumble.out", "w", stdout);
    while (cin >> n) {
        solve();;
        t++;
    }

}