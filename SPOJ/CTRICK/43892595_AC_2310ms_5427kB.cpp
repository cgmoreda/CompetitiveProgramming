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
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(i);
    }
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        idx += i;
        idx %= s.size();
        auto it = s.begin();
        advance(it, idx);
        v[*it] = i;
        s.erase(it);
    }
    for(auto i:v)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}