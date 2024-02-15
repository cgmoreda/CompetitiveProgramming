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
    cin >> n;
    vector<int> v(n);
    vin(v);
    map<int, int> mp;
    int cnt = 0;
    for (auto i: v)
    {
        mp[i]++;
        if (abs(i) > 1)
            cnt++;
    }
    bool ok = (cnt <= 1);
    if (mp.count(-1))
    {
        ok &= (cnt == 0);
        if (mp[-1] >= 2)
            ok &= (mp.count(1));
    }
    cout << ok << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}