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

    int n;
    int q;
    cin >> n;
    vector<int> v(n);
    vin(v);


    vector<int> diff(1), pref(n);
    for (int i = 1; i < n; i++)
    {
        diff.push_back(v[i] - v[i - 1]);
    }
    for (int i = 1; i < n; i++)
    {
        if ((i & 1) == 0)
            pref[i] = diff[i];
        if (i)
            pref[i] += pref[i - 1];
    }
    cin >> q;
    while (q--)
    {
        int l, r, x, y;
        cin >> l >> r;
        x = lower_bound(all(v), l) - v.begin();
        int t1 = pref[x];
        if ((x & 1) == 0)
        {
            t1 -= v[x] - l;
        }
        y = lower_bound(all(v), r) - v.begin();
        int t2 = pref[y];
        if ((y & 1) == 0)
        {
            t2 -= v[y] - r;
        }
        cout << t2 - t1 << endl;
    }
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