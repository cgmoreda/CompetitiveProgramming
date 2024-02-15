#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long

const int mod = 1e9 + 7;


const int N = 1e6;
bool prime[N];
vector<int> primes;

void sieve()
{
    for (int i = 0; i < N; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;
    for (int i = 4; i < N; i += 2)
    {
        prime[i] = 0;
    }
    for (int i = 3; i * i < N; i += 2)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i + i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 0; i <= N; i++)
        if (prime[i])
            primes.push_back(i);
}

ll power(ll x, ll k)
{
    ll ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x) % mod;
        k >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}

ll modInverse(ll a)
{
    return power(a, mod - 2);
}

ll modDivide(ll a, ll b)
{
    a = a % mod;
    ll inv = modInverse(b);
    return (inv * a) % mod;
}

void solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n);
    vin(v);
    map<int, int> mp;
    for (auto el: v)
    {
        int x = el;
        for (auto i = primes.begin(); *i * *i <= x; i++)
        {
            int cnt = 0;
            while (x % *i == 0)
                cnt++, x /= *i;
            if (cnt)
                mp[*i] = max(mp[*i], cnt);
        }
        if (x)
            mp[x] = max(mp[x], 1);
    }
    long long lc = 1;
    for (auto i: mp)
    {
        lc *= power(i.first, i.second);
        lc %= mod;
    }
    ll ans{};
    for (auto i: v)
    {
        ans += modDivide(lc, i);
        ans %= mod;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}