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
#define sq(x) ((x)*(x))
struct point
{
    double x, y;
};

double dis(point a, point b)
{
    return sqrt(sq((b.x - a.x)) + sq((b.y - a.y)));
}

int n, m;
vector<point> friends;
double dp[1 << 17];

double dope(int mask)
{
    if (mask == (1 << (2 * n )) - 1)
        return 0;

    double &ret = dp[mask];
    if (ret > 0)
        return ret;
    ret = 1e9;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            if (!(mask & (1 << i)) && !(mask & (1 << j)))
                ret = min(ret, dis(friends[i], friends[j]) + dope(mask | (1 << j) | (1 << i)));
        }
    }
    return ret;
}


void solve()
{
    friends.clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n * 2; i++)
    {
        string x;
        point a{};
        cin >> x >> a.x >> a.y;
        friends.push_back(a);
    }
    cout << fixed << setprecision(2) << dope(0) << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n && n)
    {
        cout << "Case " << t++ << ": ";
        solve();
    }

}