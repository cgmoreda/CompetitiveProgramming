#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda    

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

ll n, q, p;
vi v;

bool valid(ll x)
{
    ll cnt = 0;
    ll dif = p - q;
    for (auto i: v)
    {
        if (q > 1e18 / x)
            continue;
        if (i <= q * x)
            continue;

        ll moster = i - q * x;
        if (dif == 0)
            return false;
        cnt += (moster + dif - 1) / dif;
    }
    return cnt <= x;
}

void solve()
{
    cin >> n >> p >> q;
    v = vi(n);
    vin(v);
    ll l = 0, r = 1e18, ans = 1e18, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (valid(mid))
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

    int t = 1;
    //cin >> t;    
    while (t--)
    {
        solve();
    }

}