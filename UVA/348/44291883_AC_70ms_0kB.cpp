#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int dp[50][50];
int a[50], b[50];
int n;

int dope(int l, int r)
{
    if (l == r)
        return 0;
    int &ret = dp[l][r];
    if (~ret)
        return ret;
    ret = 1e9;
    for (int i = l; i < r; i++)
        ret = min(ret, dope(l, i) + dope(i + 1, r) + a[l] * b[r] * b[i]);
    return ret;
}

string build(int l, int r)
{
    if (l == r)
    {
        string y = "A";
        if (l < 9)
            y += char(l + '1');
        else y += "10";
        return y;
    }
    int &ret = dp[l][r];
    for (int i = l; i < r; i++)
    {
        if (ret == dope(l, i) + dope(i + 1, r) + a[l] * b[r] * b[i])
        {
            string y = "(";
            y += build(l, i);
            y += " x ";
            y += build(i + 1, r);
            y += ')';
            return y;

        }
    }
    return "ono";
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    dope(0, n - 1);
    cout << build(0, n - 1) << endl;
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