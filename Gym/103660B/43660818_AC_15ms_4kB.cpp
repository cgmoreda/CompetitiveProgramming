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
ll n, k, x, y, mx;

bool can(ll t)
{
    ll dam = 0;
    dam += min(t, k) * x;
    dam += max(t - k, 0LL) * y;
    return dam >= mx;
}

void solve()
{
    cin >> n >> k >> x >> y;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        mx = max(mx, a);
    }
    ll l = 0, r = 1e9, ans = 1e9, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (can(mid))
        {
            r = mid - 1;
            ans = min(ans, mid);
        } else l = mid + 1;
    }
    mx = 0;
    cout << ans << endl;
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