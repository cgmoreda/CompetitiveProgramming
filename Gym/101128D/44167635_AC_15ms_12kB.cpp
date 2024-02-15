#include<bits/stdc++.h>

using namespace std;
#define vin(v) for(auto &i:v)cin>>i
#define ll long long
#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>

void solve()
{
    int n, m;
    cin >> n >> m;
    map<long long, int> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            mp[i + j]++;
        }
    }
    set<int> s;
    int mx = 0;
    for (auto i: mp)
    {
        if (i.second > mx)
        {
            mx = i.second;
            s.clear();
            s.insert(i.first);
        } else if (i.second == mx)
            s.insert(i.first);
    }
    for (auto i: s)
        cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}