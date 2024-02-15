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

    int n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll o;
    cin >> o;
    ll ans = 1;
    for (auto i: s)
    {
        ans *= i;
        ans %= o;
    }
    ans--;

    if (ans &&o != 1)
        cout << "NO\n";
    else cout << "YES\n";

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