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

int dp[101][1 << 11][10][2];
int vis[101][1 << 11][10][2];
int id;
const int mod = 1e9 + 7;
int n, m;

int dope(int i, int mask, int last, int f1)
{
    if (i == m)
        return (mask & ((1 << n) - 1)) == (1 << n) - 1;

    if (vis[i][mask][last][f1] == id)
        return dp[i][mask][last][f1];

    vis[i][mask][last][f1] = id;

    int &ret = dp[i][mask][last][f1];
    ll cnt = 0;

    if (last != n - 1)
        cnt += dope(i + 1, mask | (1 << (last + 1)), last + 1, 1);
    if (last != 0)
        cnt += dope(i + 1, mask | (1 << (last - 1)), last - 1, 1);

    return ret = int(cnt % mod);
}

void solve()
{
    id++;
    cin >> n >> m;
    ll cnt = 0;

    for (int i = 1; i <= n - 1; i++)
        for (int j = 0; j < m - n + 1; j++)
            cnt += dope(j + 1, (1 << i), i, 1);

    cout << cnt % mod << endl;

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