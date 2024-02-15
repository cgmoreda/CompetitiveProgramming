#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>

void solve()
{
    char a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << ">";
    } else if (a < b)
    {
        cout <<
             '<';
    } else cout << '=';
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