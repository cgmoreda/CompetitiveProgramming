#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>


void solve()
{
    int p00 = 0, p01 = 0, p11 = 0, p10 = 0;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && t[i] == '0')
        {
            p00++;
        }
        if (s[i] == '1' && t[i] == '0')
        {
            p10++;
        }
        if (s[i] == '0' && t[i] == '1')
        {
            p01++;
        }
        if (s[i] == '1' && t[i] == '1')
        {
            p11++;
        }
    }
    if (p10 > p01)
        swap(p10, p01);
    int ans = p10;
    p01 -= p10;
    p00 += p01;
    while (p11 > p00)
    {
        p11--;
        p00++;
    }
    ans += min(p11, p00);

    cout << ans << endl;

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