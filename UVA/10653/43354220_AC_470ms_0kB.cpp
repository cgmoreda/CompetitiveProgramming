#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vector<vector<int>> G;
int n, m;
int oo = 1e9;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(int sx,int sy,int ex,int ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vector<int> dis(n + 1, oo);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int i = q.front().first;
            int j = q.front().second;

            if (i == ex && j == ey)
                return level;

            q.pop();
            if (G[i][j])continue;
            G[i][j] = 1;

            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];
                if (valid(x, y) && !G[x][y])q.push({x, y});
            }

        }
        level++;
    }
    return -1;
}

void solve() {

    G = vvi(n + 1, vi(m + 1));
    int rows;
    cin >> rows;
    for (int i = 0; i < rows; i++) {
        int row;
        cin >> row;
        int p;
        cin >> p;
        while (p--) {
            int col;
            cin >> col;
            G[row][col] = 1;
        }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    cout << bfs(sx, sy, ex, ey) << endl;


}


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1, z = 0;
    //cin >> t;
    while (cin >> n >> m && n && m) {
        //cout << "Case #" << ++z << ": ";
        solve();
    }


}