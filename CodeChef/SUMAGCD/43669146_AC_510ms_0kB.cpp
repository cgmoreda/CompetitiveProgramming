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

const int mod = 1e9 + 7;

ll gcd(ll a, ll b)
{ return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b)
{ return a / gcd(a, b) * b; }

ll nCr(ll n, ll r)
{
    ll ans = 1, div = 1;
    for (ll i = r + 1; i <= n; i++)
        ans = ans * i / div++;
    return ans;
}

ll nPr(ll n, ll r)
{
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++)
    {
        ans *= i;
        ans %= mod;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    set<int> ele;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ele.insert(a);
    }
    vi v;
    for (auto i: ele)
        v.push_back(i);
    reverse(all(v));
    n = v.size();
    if (v.size() == 1)
    {
        cout << v[0] * 2 << endl;
        return;
    }

    ll ans = 0;
    for (int i = 0; i < min(5, n); i++)
    {
        ll b = 0;
        for (auto j: v)
        {
            if (j == v[i])
                continue;
            b = gcd(b, j);
        }
        ans = max(ans, b + v[i]);
    }
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