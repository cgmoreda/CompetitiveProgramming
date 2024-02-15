#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;
    string x;
    cin >> x;

    int cnt = count(all(x), '0');
    if (cnt == x.size())
        cout << n * m << endl;
    else if (m & 1)
    {
        cnt = count(all(x), '1');
        int rem = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            rem += (x[i] == '1');
            cnt -= (x[i] == '1');
            if (cnt == rem)
                ans++;
        }
        cout << ans << endl;
    } else
    {
        x += x;
        cnt = count(all(x), '1');
        int rem = 0;
        int ans = 0;
        for (int i = 0; i < n * 2; i++)
        {
            rem += (x[i] == '1');
            cnt -= (x[i] == '1');
            if (cnt == rem)
                ans++;
        }
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}