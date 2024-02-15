#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int Nmax = 2e3 + 200;
ll dp[Nmax][Nmax];
int a[Nmax];

ll dope(int i, int j, int age = 1)
{
    if (i > j)
        return 0;
    ll &ret = dp[i][j];
    if (~ret)
        return ret;
    return ret = max(a[i] * age + dope(i + 1, j, age + 1), a[j] * age + dope(i, j - 1, age + 1));

}

void solve()
{
    memset(dp,-1,sizeof dp);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << dope(0, n - 1) << endl;
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