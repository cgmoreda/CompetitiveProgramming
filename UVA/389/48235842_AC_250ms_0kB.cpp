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
void convotobase(ll number,ll x)
{
    string out;
    if(number==0)
        out="0";

    while(number)
    {
        out+=char((number%x)+'0');
        number/=x;
    }
    for(char & i : out)
    {
        if(i>'9')
            i=(i-'9'+'A'-1);
    }
    reverse(all(out));
    cout<<setw(7)<<(out.size()>7?"ERROR":out)<<endl;

}
ll convotodeci(string number,ll x)
{
    ll out=0,base=1;
    for(int i=0;i<number.size();i++)
    {
        if(number[i]>='A')
            number[i]=(number[i]+'9'-'A'+1);
    }
    reverse(all(number));
    for(int i=0;i<number.size();i++)
    {
        out+=base*(number[i]-'0');
        base*=x;
    }
    return out;
}
    string x;
void solve() {

    ll b1,b2;
    cin>>b1>>b2;
    convotobase(convotodeci(x,b1),b2);

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
    //cin >> t;

    while (cin>>x) {
        solve();
    }


}