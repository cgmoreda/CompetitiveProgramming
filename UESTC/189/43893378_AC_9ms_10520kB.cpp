#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

int n, m;
vvi a, rooms, vis;
int id;
int wall[] = {1, 2, 4, 8};
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

//1: wall to the west
//2: wall to the north
//4: wall to the east
//8: wall to the south
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void print(vvi &x)
{
    for (auto i: x)
    {
        for (auto j: i)
            cerr << j << " ";
        cerr << endl;
    }
    cerr << endl;
}

void dfs(int i, int j)
{
    if (vis[i][j] == id)
        return;
    vis[i][j] = id;
    rooms[i][j] = id;
    for (int dir = 0; dir <= 3; dir++)
    {
        if (!(a[i][j] & wall[dir]))
        {
            int x, y;
            x = i + dx[dir];
            y = j + dy[dir];
            if (valid(x, y))
                dfs(x, y);
        }
    }

}


int countroom(int i, int j)
{
    if (vis[i][j] == id)
        return 0;
    vis[i][j] = id;
    int ret = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int x, y;
        x = i + dx[dir];
        y = j + dy[dir];
        if (valid(x, y) && rooms[i][j] == rooms[x][y])
            ret += countroom(x, y);
    }
    return ret;

}

void solve()
{
    cin >> m >> n;
    a = vvi(n, vi(m));
    rooms = vvi(n, vi(m));
    vis = vvi(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                id++;
                dfs(i, j);
            }
        }
    }
    int rcnt = id;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] <= rcnt)
            {
                id++;
                mp[rooms[i][j]] = countroom(i, j);
                mx = max(mx, mp[rooms[i][j]]);
            }
        }
    }
    int mxlarge = 0;
    int ia, ja;
    char ca;
    print(rooms);
    for (int j = 0; j < m; j++)
    {
        // 0 1 2 3
        // 1 2 4 8
        //2: wall to the north
        //4: wall to the east
        for (int i = n - 1; i >= 0; i--)
        {
            // check east
            if (j && rooms[i][j] != rooms[i][j - 1] && mp[rooms[i][j]] + mp[rooms[i][j - 1]] > mxlarge)
            {
                mxlarge = mp[rooms[i][j]] + mp[rooms[i][j - 1]];
                ia = i + 1;
                ja = j;
                ca = 'E';

            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            // check north
            if (i && rooms[i][j] != rooms[i - 1][j] && mp[rooms[i][j]] + mp[rooms[i - 1][j]] > mxlarge)
            {
                mxlarge = mp[rooms[i][j]] + mp[rooms[i - 1][j]];
                ia = i + 1;
                ja = j + 1;
                ca = 'N';
            }

        }
    }

    cout << rcnt << endl;
    cout << mx << endl;
    cout << mxlarge << endl;
    cout << ia << " " << ja << " " << ca << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}