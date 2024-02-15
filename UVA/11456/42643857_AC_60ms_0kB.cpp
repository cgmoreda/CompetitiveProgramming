#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()

const int N = 2010;
int dp[N];
int n;
vector<int> v;

void Lis() {
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = n - 1; j >= 0; j--) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

void Lds() {
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = n - 1; j >= 0; j--) {
            if (v[i] < v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

void solve() {

    cin >> n;
    v = vector<int>(n);
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    vin(v);
    vector<int> ans(n);
    memset(dp, -1, sizeof(dp));
    Lis();
    for (int i = 0; i < n; i++)
        ans[i] += dp[i];
    memset(dp, -1, sizeof(dp));
    Lds();
    for (int i = 0; i < n; i++)
        ans[i] += dp[i];
    cout << *max_element(all(ans)) - 1 << endl;
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