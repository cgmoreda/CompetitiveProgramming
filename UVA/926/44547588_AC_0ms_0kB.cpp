#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int n;
bool blocked[35][35][35][35];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
string go = "SNEW";
ll vis[35][35], dp[35][35];
int id;

bool valid(int i, int j)
{
    return i > 0 && j > 0 && i <= n && j <= n;
}

int sx, sy, ex, ey;

ll dfs(int i, int j)
{
    if (i == ex && j == ey)
        return 1;
    if (vis[i][j] == id)
        return dp[i][j];
    ll &ret = dp[i][j];
    vis[i][j] = id;
    ret = 0;
    for (int k = 1; k <= 2; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y) && !blocked[i][j][x][y])
            ret += dfs(x, y);
    }
    return ret;
}

void solve()
{
    id++;
    memset(blocked, 0, sizeof blocked);
    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;
        int dir = go.find(d);
        blocked[x][y][x + dx[dir]][y + dy[dir]] = true;
        blocked[x + dx[dir]][y + dy[dir]][x][y] = true;
    }
    cout << dfs(sx, sy) << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}