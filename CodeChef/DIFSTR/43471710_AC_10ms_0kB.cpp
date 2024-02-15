#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
int n;
map<string, int> mp;
bool ok;
string ans;

void genr(string x)
{
    if (ok)return;
    if (x.size() == n)
    {
        if (!mp.count(x))
        {
            ok = true;
            ans = x;
            return;
        }
        return;
    }
    genr(x + '1');
    genr(x + '0');
}

void solve()
{
    mp.clear();
    ans.clear();
    ok = false;
    cin >> n;
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    genr("");
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