#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
string x, y;
int n, m;
int dp[100010];
vi a;

int dope(int i) {

    if (i == n)
        return 0;

    int &ret = dp[i];
    if (~ret)return ret;
    ret = 1;
    for (int idx = i + 1; idx < n; idx++) {
        if (a[i] < a[idx]) {
            ret = max(dope(idx) + 1, ret);
        }
    }
    return ret;
}

void build(int i) {

    if (i == n)
        return;

    int &ret = dp[i];

    for (int idx = i + 1; idx < n; idx++) {
        if (a[i] < a[idx]) {
            if (ret - 1 == dp[idx]) {
                cout << a[i] << "\n";
                build(idx);
                return;
            }
        }
    }
    cout << a[i] << "\n";


}

void solve() {
    int x;
    string inp;
    a.clear();
    n = 0;
    memset(dp, -1, sizeof(dp));
    while (getline(cin, inp)) {

        if (inp.empty())break;
        x = stoi(inp);
        a.push_back(x);
    }
    n = a.size();
    cout << "Max hits: ";
    int idx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = dope(i);
        if (tmp > ans) {
            ans = tmp;
            idx = i;
        }
    }

    cout << ans << endl;
    build(idx);

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 0;
    cin >> t;
    string inp;
    getline(cin, inp);
    getline(cin, inp);
    while (t--) {
        if (z++)cout << endl;
        solve();
    }

}