#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long

ll gcd(ll a, ll b)
{ return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b)
{ return a / gcd(a, b) * b; }

pair<ll, ll> mnp(long long a, long long b)
{
    ll gc = gcd(a, b);
    return {a / gc, b / gc};
}

void solve()
{
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    map<pair<ll, ll>, int> mpl, mpr;
    for (ll i = 1; i < a; i++)
    {
        ll x = sqrt(a * a - i * i);
        if (x * x == a * a - i * i)
        {
            mpl[mnp(i, a)]++;
        }
    }
    ll ans;
    for (ll i = 1; i < b; i++)
    {
        ll x = sqrt(b * b - i * i);
        if (x * x == b * b - i * i)
        {
            mpr[mnp(i, b)]++;
        }
    }
    if (a != b)
        ans = 2;
    else
        ans = 1;
    int mul = a != b ? 2 : 1;
    for (auto i: mpl)
    {
        if (mpr[i.first])
        {
            ll c = i.first.first;
            ll d = i.first.second;
            ll e = d * d - c * c;
            e = sqrt(e);
            //cout << e << " " << c << " " << d << endl;
            if (e == c && mul == 2)
            {
                ans++;
            } else
                ans += mul;
        }
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