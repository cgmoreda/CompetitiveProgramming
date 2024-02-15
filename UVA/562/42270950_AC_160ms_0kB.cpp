/*
  requiered 2 subsets where
  union is the original set
  diffrence between sum of elements in each subset is minimal
  dp[pos][value at pos]
  good grief
 */
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int dp[101][50000];
int n;
vector<int> v;

int dope(int i, int val) {
    if (i == n) {
        return val;
    }
    int &ret = dp[i][val];
    if (ret != -1)return ret;

    int c1 = dope(i + 1, val + v[i]);
    int c2 = dope(i + 1, val - v[i]);
    return ret = min(abs(c1), abs(c2));
}

void solve() {
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dope(0,0) << endl;
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