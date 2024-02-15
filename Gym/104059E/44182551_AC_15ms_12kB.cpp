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
    double x=100,xx=0,y=0,yy=100;
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<"100.0"<<' '<<"0.0"<<endl;
    }
    else if(n==2)
    {
        cout<<"0.0"<<' '<<"100.0"<<endl;
    }
    else if(n>100000)cout<<"33.3333333"<<' '<<"66.6666667"<<endl;
    else
    {
        for (int i = 2; i < n; i++)
        {
            double temp1 = xx, temp2 = yy;
            xx = (x + xx) / 2;
            yy = (y + yy) / 2;
            x = temp1;
            y = temp2;
        }
        cout<<fixed<<setprecision(7)<<xx<<' '<<yy<<endl;
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