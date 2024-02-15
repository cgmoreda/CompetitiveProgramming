#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n, k, s;
int dp[10000][21][21];
int a[10010];

int dope(int idx, int i_tr = 0, int j_tr = 0) {
    if (i_tr + j_tr > k)return 2 * k + 1;
    int i, j;
    i = idx + i_tr;
    j = n - idx - j_tr - 1;
    if (i >= j) {
        if (i_tr + j_tr > k)return 2 * k + 1;
        else return i_tr + j_tr;
    }
    int &ret = dp[idx][i_tr][j_tr];
    if (~ret)return ret;
    if (a[i] == a[j])
        ret = dope(idx + 1, i_tr, j_tr);
    else {
        ret = min(dope(idx, i_tr, j_tr + 1), dope(idx, i_tr + 1, j_tr));
    }
    return ret;

}

void solve() {

    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = dope(0);

    if (ans == 2 * k + 1) {
        cout << "Too difficult\n";
    } else if (ans == 0)
        cout << "Too easy\n";
    else cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ": ";
        solve();;
    }

}