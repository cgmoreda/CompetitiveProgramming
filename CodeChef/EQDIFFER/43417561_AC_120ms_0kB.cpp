#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    vin(v);
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    map<int, int> mp;
    int mx = 0;
    for (auto i: v) {
        mp[i]++;
        mx = max(mx, mp[i]);
    }
    cout << min(n - 2, n - mx) << endl;
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