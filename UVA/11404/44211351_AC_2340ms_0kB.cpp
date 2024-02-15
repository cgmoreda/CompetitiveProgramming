#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vi vector<ll>
#define ll long long
#define all(v) v.begin(),v.end()

int n, k;
string x, ans;
string dp[1000][1000];

string dope(int i, int j) {
    if (i >= j) {
        if (i == j) {
            return x.substr(i, 1);
        } else return "";

    }
    string &ret = dp[i][j];
    if (ret != "*")return ret;
    if (x[i] == x[j]) {
        ret = x[i] + dope(i + 1, j - 1) + x[j];
        return ret;
    }
    string c1 = dope(i + 1, j);//delete i'th character
    string c2 = dope(i, j - 1);//delete j'th character
    if (c1.size() == c2.size()) {
        return ret = (c1 < c2) ? c1 : c2;
    } else return ret = (c1.size() > c2.size()) ? c1 : c2;
}


void solve() {

    n = (int) x.size();
    cout << dope(0, n - 1) << endl;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = "*";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = 1000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = "*";
        }
    }
    int z = 0;
    while (cin >> x) {
        solve();;
    }
}