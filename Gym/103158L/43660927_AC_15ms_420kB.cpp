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

    string x;
    cin >> x;
    if (x[0] == x.back())
    {
        cout << x.size() - 2 << endl;
    } else cout << x.size() - 1 << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("max-pair.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}