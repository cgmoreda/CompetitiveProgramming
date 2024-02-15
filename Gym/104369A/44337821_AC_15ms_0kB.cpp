#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

void solve() {
int y,yy;
cin>>y;
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++)cin>>v[i];
cin>>yy;
int ans=yy-y+1;
for(int i=0;i<n;i++)
{
   if(v[i]>=y&&v[i]<=yy)ans--;
}
cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}