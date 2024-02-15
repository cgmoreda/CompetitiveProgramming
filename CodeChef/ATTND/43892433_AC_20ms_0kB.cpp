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
    map<string, int> mp;
    vector<pair<string, string>> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i].first >> names[i].second;
        mp[names[i].first]++;
    }
    for (const auto &i: names)
    {
        cout << i.first;
        if (mp[i.first] > 1)
            cout << " " << i.second;
        cout << endl;
    }
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