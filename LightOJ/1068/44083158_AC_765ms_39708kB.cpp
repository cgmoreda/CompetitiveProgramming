#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long
string l, r;
int mod, n;

long long power(long long x, long long k)
{
    long long ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x) % mod;
        k >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}

// sum of 30 digits is always less than 30*9
// so for any mod>300 we could always assume that
// there is only 0 with that property
int dp[33][300][300][2][2][2];
int vis[33][300][300][2][2][2];
int id = 0;

int dope(int i, int rem1, int rem2, int f1, int f2, int f3)
{
    if (i == n)
        return (rem1 == 0 && rem2 == 0) && f3;
    int &ret = dp[i][rem1][rem2][f1][f2][f3];
    int &vs = vis[i][rem1][rem2][f1][f2][f3];
    if (vs == id)
        return ret;
    vs = id;
    ret = 0;
    char mx = '9', mn = '0';
    if (!f1)
        mx = r[i];
    if (!f2)
        mn = l[i];

    for (char dig = mn; dig <= mx; dig++)
    {
        int nrem1, nrem2;
        nrem1 = (rem1 + (dig - '0') * power(10, n - i - 1)) % mod;
        nrem2 = (rem2 + (dig - '0')) % mod;
        ret += dope(i + 1, nrem1, nrem2,
                    (f1 || dig != mx),
                    (f2 || dig != mn),
                    (f3 || (dig != '0')));
    }
    return ret;

}

void solve()
{
    id++;
    cin >> l >> r >> mod;
    if (mod > 290)
    {
        cout << 0 << endl;
        return;
    }
    reverse(all(l));
    while (l.size() != r.size())
        l.push_back('0');
    reverse(all(l));
    n = l.size();
    cout << dope(0, 0, 0, 0, 0, 0) << endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << z++ << ": ";
        solve();
    }

}