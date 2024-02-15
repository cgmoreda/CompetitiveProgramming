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
int n, m;
int dp[1 << 18][202], vis[1 << 18][202];
int id = 1;
int vm[202];

int dope(int mask, int i)
{
    if (i == m)
    {
        if (mask == (1 << n) - 1)
            return 0;
        else return 1e8;
    }
    if (vis[mask][i] == id)
        return dp[mask][i];
    vis[mask][i] = id;

    return dp[mask][i] = min(1 + dope(mask ^ vm[i], i + 1), dope(mask, i + 1));

}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int mask = 0;
        for (int a, j = 0; j < n; j++)
        {
            cin >> a;
            mask |= (a << j);
        }
        vm[i] = mask;
    }
    ++id;
    ll ans = dope(0, 0);
    if (ans >= 1000)
        cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++z << ": ";
        solve();
    }

}