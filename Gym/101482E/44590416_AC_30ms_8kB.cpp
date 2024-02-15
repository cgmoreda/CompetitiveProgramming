#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
ll n;
double p, s, v;

double calc1(double c)
{
    return s * (1 + 1 / c) / v;
}

double calc2(double c)
{
    return (n * pow(log2(n), c * sqrt(2))) / (p * 1e9);
}

double cal(double c)
{
    return calc1(c) + calc2(c);
}

void solve()
{
    cin >> n >> p >> s >> v;
    double l = 0, r = 1e18, mid1, mid2, ans;

    for (int i = 0; i < 400; i++)
    {
        mid1 = l + (r - l) / 3;
        mid2 = l + (r - l) * 2 / 3;
        if (cal(mid1) > cal(mid2))
        {
            l = mid1;
        } else r = mid2;
    }
    cout << fixed << setprecision(10);
    cout << cal(l) << " " << l << endl;


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