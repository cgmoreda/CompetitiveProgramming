#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda    

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

void solve()
{

    string x;
    string y;
    cin >> x >> y;
    sort(all(x));
    sort(all(y));
    reverse(all(x));
    // x<y
    while (true)
    {
        if (y.empty())
        {
            cout << "No\n";
            return;
        }
        if (x.empty())
        {
            cout << "Yes\n";
            return;
        }
        if (x.back() == y.back())
        {
            x.pop_back();
            y.pop_back();
            continue;
        }
        cout << (x.back() < y.back() ? "Yes\n" : "No\n");
        return;

    }
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