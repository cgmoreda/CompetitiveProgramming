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

const ll mod = 1000000007;

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

void solve(ll n) {

    ll k=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1; j <= n; j++)
        {
            k+=gcd(i,j);
        }
    cout<<k<<endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    //cin >> t;
    while (cin>>t) {
        if(t==0)break;
        solve(t);
    }

}