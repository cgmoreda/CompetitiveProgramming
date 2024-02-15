#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<char>>
#define ii pair<int,int>
#define ll long long



void solve()
{

    ll start = 1;
    while(1)
    {
        cout<<"? "<<start<<endl;
        ll get;
        cin>>get;
        if(get<start)
        {
            cout<<"! "<<start-get<<endl;
            return;
        }
        start*=2;
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