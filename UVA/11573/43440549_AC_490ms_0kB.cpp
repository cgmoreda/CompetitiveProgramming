#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>
#define iii tuple<int,int,int>


void solve()
{

    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> v(n + 2, vi(m + 2, -1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            v[i][j] = a - '0';
        }

    int q;
    cin >> q;
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (q--)
    {
        int xs, xe, ys, ye;
        cin >> xs >> ys >> xe >> ye;
        deque<pair<int, int>> dq;
        vector<vector<int>> vis(n + 2, vi(m + 2, 0));
        dq.push_back({xs, ys});
        int level = 0;
        while (dq.size())
        {
            int sz = dq.size();
            bool ok = false;
            while (sz--)
            {
                int cx, cy;
                cx = dq.front().first;
                cy = dq.front().second;
                dq.pop_front();
                if (vis[cx][cy] || v[cx][cy] == -1)continue;
                vis[cx][cy] = 1;
                if (cx == xe && cy == ye)
                {
                    cout << level << endl;
                    ok = true;
                }
                for (int dir = 0; dir < 8; dir++)
                {
                    int i, j;
                    i = cx + dx[dir];
                    j = cy + dy[dir];
                    if (dir == v[cx][cy])
                    {
                        dq.push_front({i, j});
                        sz++;
                    } else dq.push_back({i, j});

                }

            }
            if (ok)break;
            level++;
        }

    }


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