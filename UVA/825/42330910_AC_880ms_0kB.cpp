/*

    incredibley dissatisfying input

    anyway

    so it's basicaly calculate every path
    then dpmin on the points and count the ones with shortest lenth
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
ll dp[10002][10002];
int n, m;
vector<vector<int>> v;
int dx[] = {1, 0};
int dy[] = {0, 1};

bool valid(int i, int j) {
    return i > 0 && j > 0 && i <= n && j <= m;
}

ll dope(int i, int j) {
    if (i == n && j == m) {
        return 1;
    }
    ll &ret = dp[i][j];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int d = 0; d < 2; d++) {
        int x = i + dx[d];
        int y = j + dy[d];
        if (valid(x, y) && v[x][y] != 1) {
            ret += dope(x, y);
        }
    }
    return ret;
}


void solve() {

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    v = vector<vector<int>>(n + 2, vector<int>(m + 2));
    // getting input
    int out=0;
    while (true) {
        string x;
        getline(cin, x);
        vector<int> tmp;
        for (int j = 0; j < x.size(); j++) {
            string num;
            while (j < x.size() && x[j] != ' ') {
                num += x[j];
                j++;
            }
            if (!num.empty())
                tmp.push_back(stoi(num));
        }
        for (int j = 1; j < tmp.size(); j++) {
            v[tmp[0]][tmp[j]] = 1;
        }
        out+=tmp.size()>0;
        if(out==n)break;
    }
    // doing stuff
    cout << dope(1, 1) ;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        if(t!=0)cout<<endl;
        cout<<endl;
    }
}