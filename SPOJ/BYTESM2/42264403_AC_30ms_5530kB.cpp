/*
    top to down aproach
    make a loop goes over the first rows and checks for the best routes
    of at every v[i][j] there is only one best route so dp on that
    gg bro
 */

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define ll long long

int dp[200][200];
int cols, rows;
vector<vector<int>> v;

int dpmagic(int i, int j);

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> rows >> cols;
        v=vector<vector<int>>(rows + 3, vector<int>(cols + 3));

        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= cols; j++)
                cin >> v[i][j];

        int mx = 0;
        for (int i = 1; i <= cols; i++) {
            int c = dpmagic(1, i);
            mx = max(mx, c);
        }
        cout << mx << endl;
    }
}

int dpmagic(int i, int j) {
    if (j == 0 || j == cols + 1) {
        return -1e5;
    } else if (i == rows) {
        return v[i][j];
    } else {
        int &ret = dp[i][j];
        if (ret != -1)
            return ret;
        else {
            int c1, c2 = 0, c3 = 0;
            c1 = dpmagic(i + 1, j);
            c2 = dpmagic(i + 1, j - 1);
            c3 = dpmagic(i + 1, j + 1);
            return ret = v[i][j] + max(c1, max(c2, c3));
        }
    }
}

