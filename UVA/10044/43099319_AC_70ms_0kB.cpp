#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi G;
vi ids;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    int level = 0;
    while (q.size()) {
        int sz = q.size();
        while (sz--) {
            int point = q.front();
            q.pop();
            if (~ids[point])continue;
            else ids[point] = level;
            for (auto u: G[point])
                q.push(u);
        }
        level++;
    }
}

void solve() {
    string x;
    int p, n;
    cin >> p >> n;
    G = vvi(1);
    map<string, int> mp;
    int id = 1;
    for (int i = 0; i < p; i++) {
        string s;
        getline(cin, s);
        if (s.empty())i--;
        vector<string> tmp;
        string vert = "";
        bool coma = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ':') break;

            if (s[j] == ',') {
                if (coma) {
                    j++;
                    tmp.push_back(vert);
                    vert = "";
                    coma = false;
                    continue;
                }
                coma = true;
            }
            vert += s[j];
        }
        tmp.push_back(vert);
        for (auto name: tmp) {
            if (!mp.count(name)) {
                mp[name] = id++;
                G.push_back({});
            }
        }
        for (auto u: tmp) {
            for (auto v: tmp) {
                if (u != v)
                    G[mp[u]].push_back(mp[v]);
            }
        }
    }

    ids = vi(id + 2, -1);
    if (mp.count("Erdos, P.")) {
        bfs(mp["Erdos, P."]);
    }


    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, name);
        if (!mp.count(name)) {
            cout << name << " " << "infinity" << endl;
            continue;
        }
        id = mp[name];
        int ans = ids[id];
        if (~ans)cout << name << " " << ans << endl;
        else cout << name << " " << "infinity" << endl;
    }


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    cin >> t;
    while (t--) {
        cout << "Scenario " << z++ << endl;
        solve();
    }

}