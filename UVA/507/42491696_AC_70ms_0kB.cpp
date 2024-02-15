#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()


void solve(int t) {
    int n;
    cin >> n;
    vector<int> v(n - 1);
    vin(v);
    ll li = 0, sum = 0, mx = -1e17, l = 0, r = 0;

    for (int i = 0; i < n - 1; i++) {
        if (sum + v[i] >= v[i]) {
            sum += v[i];
        } else {
            sum = v[i];
            li = i;
        }
        if (sum > mx || (sum == mx && r - l < i - li)) {
            l = li;
            r = i;
            mx = sum;
        }
    }
    if (mx < 0) {
        cout << "Route " << t << " has no nice parts\n";
    } else cout << "The nicest part of route "<<t<<" is between stops " << l + 1 << " and " << r + 2 << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

}