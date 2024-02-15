#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()

int n, v[102][102];
int sum1 = 0;
int dp[102][102];
int tmp[102];

int kaden() {
    int sum = -1e9, ans = -1e9;
    for (int i = 1; i <= n; i++) {
        sum = max(sum + tmp[i], tmp[i]);
        ans = max(ans, sum);
    }
    sum1 = max(ans, sum1);
    return ans;
}

int dope(int l = 1, int r = 1) {

    if (r > n ) {
        return -1e9;
    }
    int &ret = dp[l][r];
    if (~ret)return ret;
    ret = kaden();
    if (r != n) {
        for (int i = 1; i <= n; i++) {
            tmp[i] += v[i][r + 1];
        }
        ret = max(ret, dope(l, r + 1));
        for (int i = 1; i <= n; i++) {
            tmp[i] -= v[i][r + 1];
        }
    }
    if (r != l) {
        for (int i = 1; i <= n; i++) {
            tmp[i] -= v[i][l];
        }
        ret = max(ret, dope(l + 1, r));
        for (int i = 1; i <= n; i++) {
            tmp[i] += v[i][l];
        }
    }
    return ret;

}

void solve() {

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i + 1][j + 1];
    }
    for (int i = 1; i <= n; i++) {
        tmp[i] = v[i][1];
    }


    cout << dope() << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin>>n) {
        solve();
    }

}