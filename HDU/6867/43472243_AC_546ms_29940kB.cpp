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
vi way;

int dfs(int node)
{
    int &ret = way[node];
    ret = 1;
    for (auto u: G[node])ret += dfs(u);
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    G = vvi(n + 1);
    for (int p, i = 2; i <= n; i++)
    {
        cin >> p;
        G[p].push_back(i);
    }
    way = vi(n + 1);
    dfs(1);
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    ll ans = 0;
    while (q.size())
    {
        int node = q.front().first;
        ll sum = q.front().second;
        q.pop();
        sum += n - way[node];
        ans = max(ans, sum);
        for (auto u: G[node])q.push({u, sum});
    }
    cout<<ans+accumulate(all(way),0LL)<<endl;
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