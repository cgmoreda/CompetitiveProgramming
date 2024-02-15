#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define vi vector<int>

int dope() {

}

void solve() {

    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    map<pair<int, int>, int> mp;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        pair<int, int> p = {-1, -1};
        for (int i = 0; i < n; i++) {
            cnt += v[i][j];
            if (v[i][j]) {
                if (!~p.first) {
                    p.first = i;
                } else if (!~p.second) {
                    p.second = i;
                }
            }
        }
        if (cnt != 2 ) {
            ok = false;
        } else if (mp[p]++ != 0) {
            ok = false;
        }
    }
    if (ok)cout << "Yes\n";
    else cout << "No\n";
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