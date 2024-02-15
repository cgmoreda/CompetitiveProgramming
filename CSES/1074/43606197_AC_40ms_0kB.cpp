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
vector<int> v;

ll calc(int x)
{
    ll ret = 0;
    for (auto i: v)
        ret += abs(i - x);
    return ret;
}

void solve()
{
    int n, k;
    cin >> n;
    v = vector<int>(n);
    vin(v);
    ll sum = accumulate(all(v), 0LL);
    sort(all(v));
    ll mincost = calc(v[n/2]);
    mincost = min(calc(v[(n+1)/2]), mincost);

    cout << mincost << endl;
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