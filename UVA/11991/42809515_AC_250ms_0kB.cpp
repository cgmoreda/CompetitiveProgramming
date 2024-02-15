#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define vi vector<int>

int dope() {

}

int n, m;

void solve() {

    cin >> m;
    const int N = 1e6 + 10;
    // vi v[N];
    vvi v(N);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a].push_back(i + 1);
    }
    while (m--) {
        int idx, el;
        cin >> idx >> el;

        if (v[el].size() < idx) {
            cout << 0 << endl;
        } else cout << v[el][idx - 1] << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n) {
        solve();
    }

}