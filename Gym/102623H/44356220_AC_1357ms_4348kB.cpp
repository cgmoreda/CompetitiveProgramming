#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define int ll
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

const ll mod = 998244353;

void solve()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m)), cur(n, vector<int>(m, 0));
    for (auto &it: grid)
        for (auto &i: it)
        {
            ll a;
            cin >> a;
            i = a % mod;
        }

    ll ans = 0;
    while (k--)
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        x--;
        if (ch == 'r')
        {
            ll sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += (grid[x][j] * ((y - cur[x][j]) % mod)) % mod;
                cur[x][j] = y;
                sum %= mod;
            }
            ans += sum;
            ans %= mod;

        } else
        {
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += (grid[i][x] * ((y - cur[i][x]) % mod)) % mod;
                cur[i][x] = y;
                sum %= mod;
            }
            ans += sum;
            ans %= mod;
        }
    }
    cout << ans << endl;

}

int32_t main()
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