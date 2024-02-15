#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >
#define repp(i, a, b) for(int i=a;i<b;i++)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define vin(a) for(auto &it: a)cin>>it
#define all(v) v.begin(),v.end()
#define ull unsigned long long
#define pi pair<int,int>
#define ld long double
#define ll long long

ll mod = 998244353;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll nCr(ll n, ll r) {
    ll ans = 1, div = 1;
    for (ll i = r + 1; i <= n; i++)
        ans = ans * i / div++;
    return ans;
}

ll nPr(ll n, ll r) {
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

ll power(ll x, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = (ret * x) % mod;
        k >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}

const int N = 1e6;
bool prime[N];
vector<int> primes;

void sieve() {
    for (int i = 0; i < N; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;
    for (int i = 4; i < N; i += 2) {
        prime[i] = 0;
    }
    for (int i = 3; i * i < N; i += 2) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i + i) {
                prime[j] = 0;
            }
        }
    }
}

ll divs(ll a) {
    ll ans = 0;
    if (a == 1)return 1;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            ans++;
            a /= i;
        }
    }
    if (a != 1)ans++;
    return ans;

}

int countbits(ll n) {
    int c = 0;
    while (n) {
        n &= (n - 1);
        c++;
    }
    return c;

}

vector<int> sums;

void solve(ll x) {

    ll j = (lower_bound(all(sums), x) - sums.begin()), a, b;
    ll l;
    a = j, b = 1;
    if ((j & 1) == 0) {
        l = sums[j] - x;
    } else {
        l = x - (sums[j - 1]) - 1;
    }
    a -= l;
    b += l;
    cout << "TERM " << x << " IS " << a << "/" << b;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sums.push_back(0);
    sums.push_back(1);

    for (int i = 2; i < 10000; i++) {
        sums.push_back(i + sums.back());
    }

    int t = 0;

    ll x = 0;
    while (cin >> x) {
        solve(x);
        cout << endl;
    }

}