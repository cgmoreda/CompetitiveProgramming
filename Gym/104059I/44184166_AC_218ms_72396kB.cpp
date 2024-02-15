#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int n,m;
const int N=5e5+5;
ll dp[N];
vector<int>c(N);
vector<vector<int>>v(N);
ll fun(int idx)
{
    if(idx==n)return 0;
    ll &ret=dp[idx];
    if(~ret)
        return ret;
    ret=1e18;
    for(int i=0;i<v[idx].size();i++)
    {
        ret=min(ret,fun(idx+i+1)-v[idx][i]);
    }
    return ret+=c[idx];
}
void solve()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {

        cin >> c[i];
        for (int j = 0; j < min(m,n - i); j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }

    }
    cout << fun(0) << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}