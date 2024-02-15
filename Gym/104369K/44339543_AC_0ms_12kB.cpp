#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int N = 33;
int grid[N][N];
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j)
{
    return i > 0 && i <= n && j > 0 && j <= m;
}

int dope()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ret += grid[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    if (valid(i + 1 * dx[dir], j + 1 * dy[dir]) && valid(i + 2 * dx[dir], j + 2 * dy[dir]))
                    {
                        if (grid[i + 1 * dx[dir]][j + 1 * dy[dir]] == 1 && grid[i + 2 * dx[dir]][j + 2 * dy[dir]] == 0)
                        {
                            grid[i][j] = 0;
                            grid[i + 1 * dx[dir]][j + 1 * dy[dir]] = 0;
                            grid[i + 2 * dx[dir]][j + 2 * dy[dir]] = 1;

                            ret = min(ret, dope());

                            grid[i][j] = 1;
                            grid[i + 1 * dx[dir]][j + 1 * dy[dir]] = 1;
                            grid[i + 2 * dx[dir]][j + 2 * dy[dir]] = 0;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

void solve()
{
    memset(grid, 0, sizeof grid);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
    }
    cout << dope() << endl;
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