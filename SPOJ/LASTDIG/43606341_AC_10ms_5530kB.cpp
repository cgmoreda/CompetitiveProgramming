#include<bits/stdc++.h> 

using namespace std;
#define ll long long
const ll mod = 10000;

ll power(ll x, ll k)
{
    ll ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x) % mod;
        k >>= 1;
        x = (x * x) % mod;
    }
    return ret;
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
        ll a, b;
        cin >> a >> b;
        cout << power(a, b) % 10<<endl;
    }

}