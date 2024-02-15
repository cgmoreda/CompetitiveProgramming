#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

// dp[current topic][how many minuitest passed in lecure]
// nothing else matters
pair<int, int> dp[1010][501];
int n, L, C, x;
int a[1001];

int sqr(int x) {
    return x * x;
}

pair<int, int> mn(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return (a.second < b.second) ? a : b;
    return (a.first < b.first) ? a : b;
}

pair<int, int> dope(int i, int ml) {


    pair<int, int> &ret = dp[i][ml];
    if (~ret.first)return ret;

    if (i == n) {
        if (ml)
            return ret = {1, (ml > 10) ? sqr(ml - 10) : -C};
        return ret = {1, 0};
    }
    ret = {1e9, 1e9};
    pair<int, int> tret;
    ml -= a[i];
    if (ml < 0) {
        return ret;
    }

    tret = dope(i + 1, ml);
    ret = mn(tret, ret);

    tret = dope(i + 1, L);
    tret.first += 1;
    if (ml)
        tret.second += (ml > 10) ? sqr(ml - 10) : -C;
    ret = mn(tret, ret);


    return ret;

}

void solve() {
    cin >> L >> C;
    int l = 0;
    memset(dp, -1, sizeof(dp));
    x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l += a[i];
        if (l > L)x++, l = a[i];
    }
    if (l)x++;
    pair<int, int> ans = dope(0, L);
    cout << "Minimum number of lectures: " << ans.first << '\n';
    cout << "Total dissatisfaction index: " << ans.second << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    //cin >> t;
    while (cin >> n) {
        if (!n)break;
        if (t)cout << '\n';
        t++;
        cout << "Case " << t << ":\n";
        solve();

    }

}