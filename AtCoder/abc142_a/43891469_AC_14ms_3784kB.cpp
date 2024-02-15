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

    int n;
    cin >> n;
    double e = 0, o = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            o++;
        else e++;
    }
    cout << fixed << setprecision(6);
    cout << (o * 1.0) / (o + e)<<endl;

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