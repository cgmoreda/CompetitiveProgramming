#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int N = 5e3 + 5;
vector<vector<int>> v1(N), v2(N);
int vis[N];
int id;
int cnt;
void dfs1(int node)
{
    if(vis[node]==id)return ;
    cnt++;
    vis[node]=id;
    for (auto it: v1[node])dfs1(it);
}
void dfs2(int node)
{
    if(vis[node]==id)return;
    cnt++;
    vis[node]=id;
    for (auto it: v2[node])dfs2(it);
}

void solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v1[x].push_back(y);
        v2[y].push_back(x);
    }

    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (int i = 0; i < n; i++)
    {
        cnt=0;
        id++;
        dfs1(i);

        if (n - cnt < a)ans1++;
        if (n - cnt < b)ans2++;
        cnt=0;
        id++;
        dfs2(i);

        if (cnt > b)ans3++;
    }
    cout << ans1 << endl << ans2 << endl << ans3 << endl;
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