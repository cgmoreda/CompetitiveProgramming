#include<bits/stdc++.h>

using namespace std;
#define vin(v) for(auto &i:v)cin>>i
#define ll long long
#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>
ll x,y,n,m;
void add(ll &val,bool temp)
{
    if(temp)
        for(int i=0;i<n;i++)val<<=1,val++;
    else
        val<<=m;
}
void solve()
{

    cin>>x>>y;
    set<ll>s;
    for(int i=1;i<=63;i++)
    {   n=i;
        for(int j=1;j<=63;j++)
        {   m=j;
            int cnt=0;
            ll val=0;
            for(int k=0;;k++)
            {
                if(k&1)cnt+=j;
                else cnt+=i;
                if(cnt>63)break;
                if(k&1)add(val,0);
                else add(val,1);
                if(val>=x&&val<=y)s.insert(val);
            }

        }
    }
    cout<<s.size();

}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}