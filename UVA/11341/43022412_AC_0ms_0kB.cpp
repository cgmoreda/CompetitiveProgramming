#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

int n, m;
int a[11][101];
int oo = 1e9;
int dp[11][101];

int dope(int i, int hoursleft) {
    if (hoursleft < 0) {
        return -oo;
    }
    if (i == n) {
        return 0;
    }
    int &ret = dp[i][hoursleft];
    if (~ret)return ret;
    ret = -oo;
    for (int j = 0; j < m; j++) {
        if (a[i][j] >= 5)
            ret = max(ret, dope(i + 1, hoursleft - j - 1) + a[i][j]);
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    double ans = (double) dope(0, m)+0.001;
    if (ans < 5) {
        cout << "Peter, you shouldn't have played billiard that much.\n";
    } else {
        cout << fixed << setprecision(2);
        cout << "Maximal possible average mark - " << (ans) / n << ".\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;
    while (t--) {
        solve();
    }
}