/*
 if the same mod value ended at a point don't calculate again
 optimize for that repetion
 dp for [index] [modvalue]
 no need to repeat those
 n<1e4
 k<1e2
 n*k<1e6 fits
 */
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int const N=1e5+1;
int n,k;
vector<int>v;
int dp[10001][101];
bool dpmagic(int i,int m);
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        v.resize(n);
        for (auto &i: v)cin >> i;
        cout << (dpmagic(1,v[0]) ? "Divisible\n" : "Not divisible\n");
    }
}
bool dpmagic(int i,int m)
{
    m%=k;m+=k;m%=k;
    if(i==n)
        return m==0;
    else {
        int &ret=dp[i][m];
        if(ret!=-1)return ret;
        bool ok=false;
        ok|= dpmagic(i+1,m+v[i]);
        ok|= dpmagic(i+1,m-v[i]);
        return ret=ok;
    }
}