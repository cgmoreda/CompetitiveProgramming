#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int N = 1e6;
vector<pair<int, int>> vp;
int n;

ll dope(ll sum)
{
    ll ret = 0;
    for (auto i: vp)
    {
        ll a = i.first;
        ll b = i.second;
        if (sum > b)
        {
            sum -= b;
            ret += b * a;
        } else
        {
            ret += sum * a;
            sum = 0;
            return ret;
        }

    }
}

void solve()
{
    vp.clear();
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vp.push_back({a, b});
        sum += b;
    }
    sum >>= 1;
    sort(all(vp));
    ll val1 = dope(sum);
    reverse(all(vp));
    ll val2 = dope(sum);
    cout << val2 - val1 << endl;
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