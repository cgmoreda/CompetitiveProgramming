#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

inline int sq(int x)
{
    return x * x;
}

struct point
{
    ll x, y, z;

    double dis(point a) const
    {
        return sqrt(sq(x - a.x) + sq(y - a.y) + sq(z - a.z));
    }
};

void solve()
{
    int n;
    cin >> n;
    double mn = 1e9;
    for (int i = 0; i < n; i++)
    {
        point a;
        cin >> a.x >> a.y >> a.z;
        mn = min(mn, a.dis({0, 0, 0}));
    }
    cout << fixed << setprecision(3);
    cout << mn << endl;
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