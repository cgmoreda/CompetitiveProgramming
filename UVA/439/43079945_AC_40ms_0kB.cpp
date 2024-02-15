#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
// direct bfs
int x, y, x2, y2;
int dx[] = {2, 2, -2, -2, 1, -1, -1, 1};
int dy[] = {1, -1, -1, 1, 2, 2, -2, -2};

bool valid(int i = 0, int j = 0) {
    return i > 0 && j > 0 && j < 9 && i < 9;
}

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    int vis[9][9] = {};
    while (!q.empty()) {
        int cx = get<0>(q.front()),
                cy = get<1>(q.front()),
                dis = get<2>(q.front());
        if (cx == x2 && cy == y2) {
           return dis;
        }
        q.pop();
        if (vis[cx][cy])continue;
        vis[cx][cy] = true;

        for (int idx = 0; idx < 8; idx++) {
            int i = cx + dx[idx];
            int j = cy + dy[idx];

            if (valid(i, j)&&!vis[i][j]) {
                q.push({i, j, dis + 1});
            }
        }
    }
}

string a, b;

void solve() {

    string chess = "abcdefgh";
    x = (int) chess.find(a[0]) + 1;
    x2 = (int) chess.find(b[0]) + 1;
    y = a[1] - '0';
    y2 = b[1] - '0';
    int ans = bfs();
    cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves.";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (cin >> a >> b) {
        solve();;
    }

}