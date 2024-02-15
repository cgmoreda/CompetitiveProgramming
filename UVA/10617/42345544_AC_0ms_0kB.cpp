#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
int n;
string x;
ll dp[100][100];
ll dope(int i, int j) {
    if (i > j) {
        return 0;
    }
    ll &ret = dp[i][j];
        if(~ret)return ret;
    ret = 1 + dope(i + 1, j) + dope(i, j - 1);
    if (x[i] != x[j])ret -= dope(i + 1, j - 1)+1;

    return ret;

}

void solve() {
    cin >> x;
    n = (int) x.size();
    memset( dp, -1, sizeof dp );
    cout << dope(0, n - 1) << endl;
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