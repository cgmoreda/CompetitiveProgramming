#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()

int dp[151][301][51];

int dope(int c, int n1, int n5, int n10) {
    if (c == 0) {
        return 0;
    }
    int &ret = dp[c][n5][n10];
    if (~ret)return ret;
    ret = 1e9;
    if (n10 > 0) {
        if (n1 > 2) {
            ret = min(ret, 4 + dope(c - 1, n1 - 3, n5 + 1, n10 - 1));
        }
        ret = min(ret, 1 + dope(c - 1, n1 + 2, n5, n10 - 1));
        return ret;
    }
    if (n5 > 0) {
        if (n5 > 1) {
            ret = min(ret, 2 + dope(c - 1, n1 + 2, n5 - 2, n10));
        }
        ret = min(ret, 4 + dope(c - 1, n1 - 3, n5 - 1, n10));
        return ret;
    }
    return ret = 8 + dope(c - 1, n1 - 8, n5, n10);
}

void solve() {

    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--) {
        int c, n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;
        cout << dope(c, n1, n5, n10) << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

}