#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define ll long long


void solve() {

    ll n;
    string x;
    cin >> n >> x;

    ll k=x.size();
    map<int,int>factors;
    for(ll i=n;i>0;i-=k)
    {
        ll z=i;
       for(int j=2;j*j<=z;j++){
           while(z%j==0)
           {
               factors[j]++;
               z/=j;
           }
       }
       if(z!=1){
           factors[z]++;
       }
    }
    ll ans=1;
    for(auto i:factors)
    {
        if(ans<(1e18/(i.second+1)))
        {
            ans*=(i.second+1);
        }
        else {
            cout<<"Infinity\n";
            return;
        }
    }

    cout<<ans<<endl;


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;

    cin >> t;
    for(int i=1;i<=t;i++) {
        cout<<"Case "<<i<<": ";
        solve();
    }


}