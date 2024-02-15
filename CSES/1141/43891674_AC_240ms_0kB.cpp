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
    int ans = 0;
    for (int i = 0, j = 0; j < n; i++)
    {
        while (j < n && mp[v[j]] == 0)
        {
            mp[v[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        mp[v[i]]--;
    }
    cout << ans << endl;
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