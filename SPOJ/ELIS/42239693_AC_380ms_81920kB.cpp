#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int N = 1e5;

vector<int> v;
int dp[N][200];
int n;

int dpmagic(int i = 0, int mxval = 0) {
    if (i == n)
        return 0;
    int &ret = dp[i][mxval];
    if (ret != -1)return ret;
    int c1 = 0, c2 = 0;
    c1 = dpmagic(i + 1, mxval);
    if (mxval < v[i])
        c2 = dpmagic(i + 1, v[i]) + 1;
    return ret = max(c1, c2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (auto &i: v)cin >> i;
    memset(dp, -1, sizeof(dp));
    cout << dpmagic() << endl;


}