#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

string x;
int n;
int dp[1001][1001];

int dope(int i, int j) {

    if (i >= j)return 0;

    int &ret = dp[i][j];
    if (~ret)return ret;

    if (x[i] == x[j])
        return ret = dope(i + 1, j - 1);

    int c1 = 1 + dope(i + 1, j);//insert at j + 1
    int c2 = 1 + dope(i, j - 1);//insert at i
    return ret = min(c1, c2);
}

int idxshift = 0;
string out;

void build(int i, int j) {

    if (i >= j) {
        cout << out;
        if (i == j)cout << x[i];
        reverse(all(out));
        cout << out;
        return;
    }
    int &ret = dp[i][j];


    if (x[i] == x[j]) {
        out += x[i];
        build(i + 1, j - 1);
        return;
    }
    int c1 =  dope(i + 1, j);//insert x[i] at j + 1
    int c2 =  dope(i, j - 1);//insert a[j] at i
    if (c1 + 1 == ret) {
        out += x[i];
        build(i + 1, j);
    } else if (c2 + 1 == ret) {
        out += x[j];
        build(i, j - 1);
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));

    n = x.size();
    cout << dope(0, n - 1) << ' ';
    out.clear();
    build(0, n - 1);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    while (cin >> x) {
        solve();
    }
}