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
ll dp[12][12][2][2];

ll dope(string &b, int i = 0, int xnt = 0, int state = 0, int state2 = 0)
{
    if (i >= b.size())
        return xnt;
    ll &ret = dp[i][xnt][state][state2];
    if (~ret)return ret;
    ret = 0;
    char mx = '9';
    if (!state)
        mx = b[i];
    for (char j = '0'; j <= mx; j++)
    {
        bool st2 = (state2 || i == b.size() - 1);
        int cnt = xnt;
        if (j == '0' && st2)
            cnt++;
        ret += dope(b, i + 1, cnt, (state | (j != mx)), state2 | (j != '0'));
    }
    return ret;
}

ll ans(ll a, ll b)
{
    string l = to_string(a - 1), r = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll x = dope(r);
    if (a == 0)
        return x;
    memset(dp, -1, sizeof(dp));
    ll y = dope(l);
    return x - y;
}

int z = 1;

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << "Case " << z++ << ": " << ans(a, b) << endl;
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