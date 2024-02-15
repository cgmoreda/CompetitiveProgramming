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

int n, k;
int dp[1 << 13][100][13];

int dope(int mask, int cnt = 0, int last = -1)
{
    if (mask == (1 << n) - 1)
    {
        return cnt == k;
    }
    int &ret = dp[mask][cnt][last + 1];
    if (~ret)return ret;
    ret = 0;
    int ncnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            ncnt++;
        } else
        {
            ret += dope(mask | (1 << i), cnt + ncnt, i);
        }
    }
    return ret;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << dope(0, 0) << endl;
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