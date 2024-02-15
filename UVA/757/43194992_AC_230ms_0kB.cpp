#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vi vector<ll>
#define ll long long
#define all(v) v.begin(),v.end()

ll n, k, th;
ll dp[27][1000];
ll t[27], f[27], d[27];

ll dope(ll i = 0, ll rh = th) {

    if (i == n || rh <= 0)
        return 0;


    ll &ret = dp[i][rh];
    if (~ret)return ret;
    ll sum = 0, fx = f[i];
    while (rh >= 0) {
        ret = max(ret, sum + dope(i + 1, rh - t[i]));
        rh -= 5;
        sum += fx;
        fx = max(0LL, fx - d[i]);
    }
    return ret;
}

vi ans;

void build(ll i = 0, ll rh = th) {

    if (i == n || rh <= 0)
        return;

    ll &ret = dp[i][rh];


    ll sum = 0, fx = f[i], go = -1, times = 0;


    while (rh >= 0) {
        if (rh >= 0) {
            if (ret == sum + dope(i + 1, rh - t[i])) {
                go = rh - t[i];
                ans[i] = times * 5;
            }
        }
        times++, rh -= 5, sum += fx;
        fx = max(0LL, fx - d[i]);
    }

    build(i + 1, go);
}


void solve() {

    memset(dp, -1, sizeof(dp));
    cin >> th;
    th *= 60;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> t[i];
        t[i] *= 5;
    }
    ll fish = dope();
    ans = vi(n);
    build();
    int z = 0;
    for (auto i: ans) {
        if (z++)cout << ", ";
        cout << i;
    }
    cout << endl;
    cout << "Number of fish expected: " << fish << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z = 0;
    while (cin >> n && n) {
        if (z++)cout << endl;
        solve();
    }
}