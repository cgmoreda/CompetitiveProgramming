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

    int n, m;
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        s.insert(t);
    }
    vector<int> v;
    for (const auto& it: s)
        v.push_back(it.size() + 1);
    sort(all(v));
    int cnt = 0, rem = n + 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > rem)break;
        cnt++;
        rem -= v[i];
    }
    cout << cnt;
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