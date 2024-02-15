#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

ll dp_a[151][15100], dp_b[151][15200];
int a[151], b[151];
int n, m, w, k;
const int mod = 1e9 + 7;

ll dope_a(int i, int rem) {
    if (i == n || rem < 0)
        return !rem;
    ll &ret = dp_a[i][rem];
    if (~ret)return ret;
    return ret = (dope_a(i + 1, rem) + dope_a(i + 1, rem - a[i])) % mod;
}

ll dope_b(int i, int rem) {
    if (i == m || rem < 0)
        return !rem;
    ll &ret = dp_b[i][rem];
    if (~ret)return ret;
    return ret = (dope_b(i + 1, rem) + dope_b(i + 1, rem - b[i])) % mod;
}


void solve() {

    memset(dp_a, -1, sizeof(dp_a));
    memset(dp_b, -1, sizeof(dp_b));

    cin >> n >> m >> k >> w;

    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)cin >> b[i];
    vector<ll> v1(w + 1), v2(w + 1);
    for (int sum = 0; sum <= w; sum++)
        v1[sum] += dope_a(0, sum), v2[sum] += dope_b(0, sum);
    ll ans = 0;
    for (int s1 = 0, s2 = w; s1 <= w; s1++, s2--) {
        if (abs(s1 - s2) <= k) {
            ans += v1[s1] * v2[s2] % mod;
            ans %= mod;
        }
    }
    cout << ans % mod << endl;


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}