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
    ll n, k, x;
    cin >> n >> k >> x;
    deque<ll> v(n);
    vin(v);

    sort(all(v));
    ll sum = 0;
    for (auto i: v)sum += i;
    reverse(all(v));
    while (k-- > 0 && v[0] + v[1] > x)
    {
        sum -= v[0];
        sum -= v[1];
        sum += x;
        v.pop_front();
        v.pop_front();
    }
    cout << sum << endl;
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