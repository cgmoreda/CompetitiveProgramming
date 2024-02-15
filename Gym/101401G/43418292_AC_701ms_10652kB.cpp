#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>


void solve() {
    int n, q;
    cin >> n >> q;
    string x;
    cin >> x;
    set<int> s;
    int R = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++) {
        s.insert(i);
        if (x[i] == 'R')R++;
        if (x[i] == 'B')b++;
        if (x[i] == 'G')g++;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        stack<int>st;
        for (auto it = s.lower_bound(l); it != s.end() && *it <= r; it++) {
            if (x[*it] == 'R') {
                R--;
                b++;
            }
            if (x[*it] == 'B') {
                b--;
                g++;
            }
            if (x[*it] == 'G') {
                g--;
                R++;
            }
            st.push(*it);
        }
        while(st.size())s.erase(st.top()),st.pop();
        cout<<R<<" "<<g<<" "<<b<<endl;
    }


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