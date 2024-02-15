#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
string x;
int n;
int dp[1001][1001];

int dope(int i, int j) {
    if (i > j) {
        return 0;
    }
    int &ret = dp[i][j];
    if (~ret)return ret;
    ret = 1e9;
    // if equal
    if (x[i] == x[j])
        ret = min(ret, dope(i + 1, j - 1));
    // replace at i to match at j or vise versa
    ret = min(ret, 1 + dope(i + 1, j - 1));
    // add at pos i
    ret = min(ret, 1 + dope(i + 1, j));
    // add at pos j
    ret = min(ret, 1 + dope(i, j - 1));

    return ret;

}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> x;
    cout << dope(0, x.size() - 1) << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        solve();
    }

}
