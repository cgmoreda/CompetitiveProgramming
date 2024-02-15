#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi grid;
vvi vis;
int n, m;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool valid(int i, int j) {
    return i > 0 && j > 0 && i < n && j < m;
}

int cntbits(int xdf) {
    int cnt = 0;
    while (xdf)xdf &= xdf - 1, cnt++;
    return cnt;
}

void print(vvi &v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << cntbits(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve() {
    grid = vvi(n + 2, vi(m + 2));
    vis = vvi(n + 2, vi(m + 2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                for (int x = i; x < i + 2; x++)
                    for (int y = j; y < j + 2; y++)
                        vis[x][y] = 31;
            }
        }
    }
    int xb, yb, xe, ye, level = 0, cx, cy, cd;
    string drstr;
    cin >> xb >> yb >> xe >> ye >> drstr;
    int dir = string("nesw").find(drstr[0]);
    queue<tuple<int, int, int>> q;
    q.push({xb, yb, dir});
    //print(vis);
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {
            cx = get<0>(q.front()), cy = get<1>(q.front()), cd = get<2>(q.front());
            q.pop();
            if (!valid(cx, cy) || (vis[cx][cy] & (1 << cd)))continue;
            if (cx == xe && cy == ye) {
                cout << level << endl;
               // print(vis);
                return;
            }
            vis[cx][cy] |= (1 << cd);

            for (int i = 1; i <= 3; i++) {
                int tx, ty;
                tx = cx + dx[cd] * i;
                ty = cy + dy[cd] * i;
                if (!valid(tx, ty) || (vis[tx][ty] & (1 << cd)))break;
                q.push({tx, ty, cd});
            }

            for (int i = -1; i <= 1; i += 2)
                q.push({cx, cy, (cd + i + 4) % 4});

        }
        //cout << level << endl;
        //print(vis);
        level++;

    }
    cout << -1 << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        solve();;
    }

}