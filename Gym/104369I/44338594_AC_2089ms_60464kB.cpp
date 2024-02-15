#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
vector<vector<int>>v;
vector<pair<int,int>>idx(1e6+5);
bool can(int mid)
{
    vector<pair<int,int>>temp;
    for(int i=0;i<=mid;i++)
    {
        temp.push_back({idx[i].first,idx[i].second});
    }
    sort(all(temp));
    for(int i=1;i<=mid;i++)
    {
        if(temp[i].second<temp[i-1].second)return false;
    }
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    v = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
            idx[v[i][j]].first=i;
            idx[v[i][j]].second=j;
        }
int l=0,r=n*m-1,mid,ans;
while(l<=r)
{
    mid=l+(r-l)/2;
    if(can(mid))l=mid+1,ans=mid;
    else r=mid-1;
}
cout<<ans+1<<endl;
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