#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n, m;
bool vis[9][9][9][9][9][9][9][9][9];
map<vector<int>, string> mp;

void bfs(vi to) {
    queue<pair<vi, string>> q;
    memset(vis, 0, sizeof(vis));
    q.push({to, ""});
    int level = 0;
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {

            vi cat = q.front().first;
            string ops = q.front().second;
            q.pop();
            if (vis[cat[0]][cat[1]][cat[2]][cat[3]][cat[4]][cat[5]][cat[6]][cat[7]][cat[8]])continue;
            vis[cat[0]][cat[1]][cat[2]][cat[3]][cat[4]][cat[5]][cat[6]][cat[7]][cat[8]] = true;
            mp[cat] = ops;
            int pos = 0;
            for (int i = 0; i < 9; i++) {
                if (cat[i] == 0) {
                    pos = i;
                    break;
                }
            }
            if (pos != 0 && pos != 1 && pos != 2) {

                swap(cat[pos], cat[pos - 3]);
                q.push({cat, ops + 'd'});
                swap(cat[pos], cat[pos - 3]);

            }
            if (pos != 6 && pos != 7 && pos != 8) {
                swap(cat[pos], cat[pos + 3]);
                q.push({cat, ops + 'u'});
                swap(cat[pos], cat[pos + 3]);
            }
            if (pos != 0 && pos != 3 && pos != 6) {

                swap(cat[pos], cat[pos - 1]);
                q.push({cat, ops + 'r'});
                swap(cat[pos], cat[pos - 1]);
            }
            if (pos != 2 && pos != 5 && pos != 8) {

                swap(cat[pos], cat[pos + 1]);
                q.push({cat, ops + 'l'});
                swap(cat[pos], cat[pos + 1]);
            }
        }
        level++;
    }
}

void solve() {

    vector<int> a;
    for (int i = 0; i < 9; i++) {
        char x;
        cin >> x;
        if (x == 'x')
            x = 0;
        else
            x = x - '0';
        a.push_back(x);
    }
    if (mp.count(a)) {
        string tmp = mp[a];
        reverse(all(tmp));
        cout << tmp << "\n";
    } else cout << "unsolvable\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bfs({1, 2, 3, 4, 5, 6, 7, 8, 0});
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        if (t)cout << endl;;
    }

}