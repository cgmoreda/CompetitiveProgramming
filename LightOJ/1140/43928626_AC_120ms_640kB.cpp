#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>
ll dp[12][12][2][2][2];
int vis[12][12][2][2][2];
string l, r;
int id;

ll dope(int i, int cnt, int f1, int f2, int f3)
{

    if (i == l.size())
        return cnt;

    ll &ret = dp[i][cnt][f1][f2][f3];
    if (vis[i][cnt][f1][f2][f3] == id)
        return ret;

    vis[i][cnt][f1][f2][f3] = id;

    ret = 0;
    char mx = '9', mn = '0';
    if (!f1)
        mx = r[i];
    if (!f2)
        mn = l[i];
    for (char dig = mn; dig <= mx; dig++)
    {
        int xnt = (f3 && dig == '0') || (i == l.size() - 1 && dig == '0');

        ret += dope(i + 1, cnt + xnt, f1 || (dig != mx), f2 || (dig != mn), f3 || dig != '0');
    }
    return ret;
}

void solve()
{
    id++;
    cin >> l >> r;
    reverse(all(l));
    while (l.size() != r.size())
        l.push_back('0');
    reverse(all(l));

    cout << "Case " << id << ": " << dope(0, 0, 0, 0, 0) << endl;

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