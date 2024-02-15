/*
    problem
    t test cases each having the following
    N objects
    p1      w1
    p2      w2
    p...    w...
    p prices w weight
    pN      wN
    G number of people
    MW max weight for each person

    basic aproach
    just napsack for every person and dp for the remaining space
    dp on [pos][rem]
 */
#include<iostream>
#include<vector>
#include<cstring>

#define ll long long
using namespace std;
vector<int> p, w;
ll n, dp[3001][3002];

ll dope(int i, int rem) {
    if (rem == 0 || i == n) {
        return 0;
    }
    ll &ret = dp[i][rem];

    if (ret != -1)
        return ret;

    ll c1, c2 = 0;
    c1 = dope(i + 1, rem);
    if (rem >= w[i])
        c2 = p[i] + dope(i + 1, rem - w[i]);

    return ret = max(c1, c2);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    p = vector<int>(n);
    w = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];
    }
    int G;
    cin >> G;
    ll sum = 0;
    int k;
    while (G--) {
        cin >> k;
        sum += dope(0, k);
    }
    cout << sum << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}