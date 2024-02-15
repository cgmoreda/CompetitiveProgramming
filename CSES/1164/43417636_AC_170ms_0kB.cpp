#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
struct da {
    int l, r, i;
};

bool comp(da a, da b) {
    if (a.r == b.r) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

void solve() {
    int n;
    cin >> n;
    vector<da> v(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].i = i;
    }
    sort(all(v), comp);
    int z = 0;
    vi out(n);
    for (int i = 0; i < n; i++) {

        auto it = s.lower_bound({v[i].l, 0});
        if (it == s.begin()) {
            s.insert({v[i].r, ++z});
            out[v[i].i] = z;
        } else {
            it--;
            out[v[i].i] = it->second;
            pair<int, int> tmp = *it;
            s.erase(it);
            s.insert({v[i].r, tmp.second});
        }
    }

    cout << z << endl;
    for (auto i: out)cout << i << " ";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}