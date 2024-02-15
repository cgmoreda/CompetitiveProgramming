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
vector<pair<string, string>> sw;
set<string> s;

string conv(const string &x, int idx) {
    string old = sw[idx].first, nw = sw[idx].second;

    string p1;
    int srch = (int) x.find(old, 0);
    for (int i = 0; i < x.size(); i++) {
        if (i == srch) {
            p1 += '*';
            i += (int) old.size() - 1;
            srch = (int) x.find(old, i + 1);
        } else {
            p1 += x[i];
        }
    }
    string ret;
    for (auto i: p1)
        if (i == '*')ret += nw;
        else ret += i;
    return ret;

}

void bfs(string at, string to) {
    queue<string> q;
    s.clear();
    q.push({at});
    int level = 0;
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {
            string cat = q.front();
            q.pop();
            if (s.find(cat) != s.end()||cat.size()>10) continue;
            s.insert(cat);
            if (cat == to) {
                cout << level << endl;
                return;
            }
            for (int i = 0; i < n; i++) {
                if (cat.find(sw[i].first) != string::npos) {
                    q.push(conv(cat, i));
                }
            }
        }
        level++;
    }
    cout << -1 << endl;
}

void solve() {

    string a, b;
    sw.clear();
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sw.push_back({a, b});
    }
    cin >> a >> b;
    bfs(a, b);

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n && n) {
        solve();
        cout << flush;;
    }

}