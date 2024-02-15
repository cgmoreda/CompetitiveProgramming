#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>

void solve()
{

    ll n;
    ll a, b, z = 0;
    cin >> a >> b;
    map<int, int> mp;
    while (a > 1)
    {
        mp[a] = z++;
        a >>= 1;
    }
    int x = 0;
    while (b > 1)
    {
        if (mp.count(b))
        {
            cout << x + mp[b] << endl;
            return;
        }
        b >>= 1;
        x++;
    }
    cout << x + z << endl;

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