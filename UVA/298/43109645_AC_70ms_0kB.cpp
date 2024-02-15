#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

int track[32][32], vis[32][32][32][32];
int n, m;
int x, y, x2, y2, ans;
int dx[] = {0, -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, 0, -1, -1, 1, 1, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool svalid(int si, int sj) {
    return si >= -3 && sj >= -3 && si <= 3 && sj <= 3;
}

void bfs() {
    // x,y,speedx,speedy
    queue<tuple<int, int, int, int, int>> q;
    q.push({x, y, 0, 0, 0});
    memset(vis, 0, sizeof(vis));
    if (x == x2 && y == y2) {
        ans = 0;
        return;
    }
    while (!q.empty()) {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int sx = get<2>(q.front());
        int sy = get<3>(q.front());
        int ds = get<4>(q.front());
        q.pop();

        if (track[cx][cy] || vis[cx][cy][sx+6][sy+6])
            continue;
        vis[cx][cy][sx+6][sy+6] = 1;
        if (cx == x2 && cy == y2) {
            ans = ds;
            return;
        }
        for (int dr = 0; dr < 9; dr++) {
            int i, j, si, sj;
            si = sx + dx[dr];
            sj = sy + dy[dr];
            i = cx + si;
            j = cy + sj;
            if (valid(i, j) && svalid(si, sj))
                q.push({i, j, si, sj, ds + 1});
        }

    }
    ans = -1;
}


void solve() {
    cin >> n >> m;
    cin >> x >> y >> x2 >> y2;
    int p;
    cin >> p;
    memset(track, 0, sizeof(track));
    while (p--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= b; i++) {
            for (int j = c; j <= d; j++) {
                track[i][j] = 1;
            }
        }
    }

    bfs();
    if (ans == -1) {
        cout << "No solution.\n";
    } else cout << "Optimal solution takes " << ans << " hops.\n";
    cout << flush;
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