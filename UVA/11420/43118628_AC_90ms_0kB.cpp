#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

int n, s;
ll dp[101][101][2];
vi a;
ll oo = 1e14;

ll dope(int i, int locked, int pr = 1) {

    if (i == 0)
        return locked == s;

    ll &ret = dp[i][locked][pr];
    if (~ret)
        return ret;

    ret = dope(i - 1, locked + pr, 1)+ dope(i - 1, locked, 0);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> s) {
        if (n + s < 0)break;
        memset(dp, -1, sizeof(dp));
        cout << dope(n, 0) << endl;

    }

}