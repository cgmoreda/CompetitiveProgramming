#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>


int dx[] = {-1, 0, 0};
int dy[] = {0, -1, 1};

int n, m;
vvc grid;

void dfs(int i, int j, int l=0) {
    string path = "IEHOVA#";
    vector<string> pthmve = {"forth", "left", "right"};

    for (int idx = 0; idx < 3; idx++) {
        int x, y;
        x = i + dx[idx];
        y = j + dy[idx];
        if (x < 0 || y < 0 || x >= n || y >= m) continue;
        if (grid[x][y] == path[l]) {
            cout << pthmve[idx];
            if(l+1==path.size())return;
            cout<<" ";
            dfs(x, y, l + 1);

        }
    }

}

void solve() {
    cin >> n >> m;
    grid = vvc(n, vc(m));
    for (auto &i: grid)for (auto &j: i)cin >> j;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '@')dfs(i, j, 0);
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();;
    }

}