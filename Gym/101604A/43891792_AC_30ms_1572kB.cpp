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


    string x;
    cin >> x;
    int n = x.size();
    vector<pair<char, char>> ch;
    for (int i = 0; i < n / 2; i++)
    {
        if (x[i] != x[n - i - 1])
        {
            ch.push_back({x[i], x[n - i - 1]});
        }
    }
    if (ch.size() == 2)
    {
        if ((ch[0].first == ch[1].second && ch[1].first == ch[0].second) ||
            (ch[1].first == ch[0].first && ch[1].second == ch[0].second))
        {
            cout << "YES\n";
        } else cout << "NO\n";
    } else if (ch.size() == 1 && (n & 1))
    {
        if (x[n / 2] == ch[0].first || x[n / 2] == ch[0].second)
            cout << "YES\n";
        else cout << "NO\n";
    } else if (ch.size() == 0)
    {
        cout << "YES\n";
    } else cout << "NO\n";
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