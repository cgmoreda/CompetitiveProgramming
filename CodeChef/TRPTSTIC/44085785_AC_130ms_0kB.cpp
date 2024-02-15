#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long

vector<vector<ll>> rooms, rmog;
ll n, m, k;

ll calc(int x1, int x2, int y1, int y2)
{
    x1--;
    y1--;
    ll a = rooms[x1][y1];
    ll b = rooms[x1][y2];
    ll c = rooms[x2][y2];
    ll d = rooms[x2][y1];
    return c - b - d + a;
}

bool can(ll x)
{
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x1 = max(1LL, i - x), x2 = min(i + x, n), y1 = max(1LL, j - x), y2 = min(j + x, m);
            if (rmog[i][j])
                mx = max(mx, calc(x1, x2, y1, y2));
            if (mx >= k)
                return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m >> k;
    rooms = vector<vector<ll>>(n + 2, vector<ll>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> rooms[i][j];
    rmog = rooms;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            rooms[i][j] += rooms[i - 1][j];

    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            rooms[i][j] += rooms[i][j - 1];
    k++;
    if (rooms[n][m] < k)
    {
        cout << -1 << endl;
        return;
    }
    ll l = 0, r = max(n, m), mid, ans = LONG_MAX;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (can(mid))
        {
            r = mid - 1;
            ans = min(ans, mid);
        } else l = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}