#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define clr(v, d)			memset(v, d, sizeof(v))
#define fx(x) fixed<<setprecision(x)
#define sz(x) x.size()
ll gcd(ll a, ll b) { return(b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
const int N = 1e5 + 100;
const int mod = 1e9 + 7;
//ll power(ll n, ll k) { if (k == 0)return 1; ll ret = 1; if (k & 1) ret = n; return (ret * power((n * n) % mod, k >> 1)) % mod; }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less: it is the basic for comparison of two function. Use less_equal for ordered multiset.
// order_of_key(k): Number of items  strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero)
ll prime[10000002];
void  sieve_v2(){
    for (int i = 0; i < N; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 4; i < N; i += 2){
        prime[i] = 0;
    }
    for (int i = 3; i * i < N; i += 2){
        if (prime[i]){
            for (int j = i * i; j < N; j += i + i){
                prime[j] = 0;
            }
        }
    }
}
int n;
vector<int>v, fr;
void rec(int id)
{
    if (v.size() == n) {
        if (!prime[v[n - 1] + 1])return;
        cout<<"1";
        for (int i = 1; i < v.size(); i++)cout << " "<<v[i];
        cout << "\n";
        return;
    }
    for (int i = (id%2)+1; i <= n; i += 2)
    {
        if (!fr[i] && prime[id + i])
        {
            fr[i] = 1;
            v.push_back(i);
            rec(i);
            v.pop_back();
            fr[i] = 0;
        }
    }
}
void solve() {
    int test=1;
    while(cin>>n)
    {
        fr = vector<int>(n + 1);
        v.push_back(1);
        fr[1] = 1;
        if(test>1)cout<<"\n";
        cout << "Case " << test << ":\n";
        rec(1);
        v.pop_back();
        test++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    sieve_v2();
    //cin>>t;
    while (t--)solve();
}
