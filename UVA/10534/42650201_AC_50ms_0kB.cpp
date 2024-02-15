#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()

const int N = 10010;
int n;
vector<int> v;

void Lis(vector<int> &lis) {
    vector<int> tmp;
    for (int i = 0; i < n; i++) {

        int cur = lower_bound(all(tmp), v[i]) - tmp.begin();
        if (cur == tmp.size())
            tmp.push_back(v[i]);
        else tmp[cur] = v[i];
        lis[i] = tmp.size();
    }
}


void solve() {
    vector<int> lis(n), lds(n);
    v = vector<int>(n);
    vin(v);
    Lis(lis);
    reverse(all(v));
    Lis(lds);
    reverse(all(lds));
    int mx = 1;
    for (int i = 0; i < n; i++)
        mx = max(2 * min(lis[i], lds[i]) - 1, mx);
    cout << mx << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 75;
    //cin >> t;
    while (cin >> n) {
        solve();
    }

}