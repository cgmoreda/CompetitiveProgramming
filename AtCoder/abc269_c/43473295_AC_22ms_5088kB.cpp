#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda    

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

void solve()
{

    ll n;
    cin >> n;
    vector<int> idx;

    for (int i = 0; i < 60; i++)
    {
        if (n & (1LL << i))
            idx.push_back(i);
    }
    set<ll> out;
    out.insert(0);
    for (ll mask = 0; mask < (1 << idx.size()) ; mask++)
    {
        ll x = 0;
        for (int i = 0; i < idx.size(); i++)
        {
            if (mask & (1LL << i))
                x |= (1LL << idx[i]);
        }
        out.insert(x);
    }
    for (ll i: out)
    {
        cout << i << "\n";
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