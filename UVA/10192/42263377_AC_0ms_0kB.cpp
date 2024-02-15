/*



    standard longest common subsequence
    first time to implement so might get a bit buggy

    dp on i and j


*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

string x, y;
int dp[101][101], n, m;

int dpmagic(int i = 0, int j = 0) {
    if (i == n || j == m) {
        return 0;
    }

    int &ret = dp[i][j];
    if (ret != -1)return ret;

    if (x[i] == y[j])
        ret = max(ret, 1 + dpmagic(i + 1, j + 1));
    ret = max(ret, dpmagic(i + 1, j));
    ret = max(ret, dpmagic(i, j + 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while (true) {
        getline(cin, x);
        if (x == "#")
            break;
        else getline(cin, y);
        cout<<"Case #"<<t++<<": you can visit at most ";

        n=x.size();
        m=y.size();
        memset(dp,-1,sizeof(dp));
        cout<<dpmagic();
        cout<<" cities.\n";

    }
}
