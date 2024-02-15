#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int n, m;


//don't forget to define mod
long long power(long long x, long long k)
{
    long long ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x) % n;
        k >>= 1;
        x = (x * x) % n;
    }
    return ret;
}


void solve()
{
    int k;
    cin >> k;
    n++;
    ll a[20];
    for (int j = 0; j <= k; j++)
        cin >> a[j];

    set<ll> s;

    for (int i = 0; i <= m; i++)
    {
        ll sum = 0;
        for (int j = 0; j <= k; j++)
            sum += power(i, j) * a[j];
        s.insert(sum % n);
    }
    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m && n)
    {
        solve();
    }

}