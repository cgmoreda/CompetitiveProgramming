#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
string x;
int n;
int dp[1001][1001];
int h;
vector<int> r, d;

ll dope(int i, ll rem) {
    if (i == n) {
        if (rem < 0)
            return 0;
        else return 1e14;
    }
    if(rem<0)
    {
        return dope(i + 1, rem);
    }
    return min(dope(i + 1, rem - (h * r[i])) + d[i], dope(i + 1, rem));
}

void solve() {

    cin >> n;
    r = vector<int>(n);
    d = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> r[i] >> d[i];
    }


    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll rem;
        cin >> rem >> h;

        cout << "Case " << i+1 << ": ";
        ll ans = dope(0, rem);
        if (ans >= (ll) 1e14)cout << "IMPOSSIBLE" << '\n';
        else
            cout << ans << '\n';
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