#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda    

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi G;

void solve()
{

    int n;
    cin >> n;
    G = vvi(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    ll ans=0;
    for(auto i:G)
        ans+=max(0LL,(ll)i.size()-1);
    cout<<ans<<endl;
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