#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

void solve()
{
    int w, h, n, A, B, mn, mx;
    cin >> w >> h >> n;

    vector<int> q(n), p(n), a, b;
    set<int> sq, sp, ls;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        sq.insert(q[i]);
        cin >> p[i];
        sp.insert(p[i]);
    }

    cin >> A;
    a = vi(A);
    vin(a);
    cin >> B;
    b = vi(B);
    vin(b);
    a.push_back(w);
    b.push_back(h);

    mn = n, mx = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = *lower_bound(all(a), q[i]);
        int y = *lower_bound(all(b), p[i]);
        mp[{x, y}]++;
    }
    for (auto i: mp)
        mx = max(mx, i.second);
    if (mp.size() == (A + 1) * (B + 1))
    {
        for (auto i: mp)
            mn = min(mn, i.second);
    } else mn = 0;

    cout << mn << " " << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}