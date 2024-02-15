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

void solve()
{
    int n, k;
    cin >> n >> k;
    int totalp = 0;
    bool ok = true;
    int out;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!ok)continue;
        totalp += a;
        if (totalp < k)
        {
            ok = false;
            out = i + 1;
        } else totalp -= k;
    }
    if (ok)cout << "YES\n";
    else cout << "NO " << out << "\n";
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