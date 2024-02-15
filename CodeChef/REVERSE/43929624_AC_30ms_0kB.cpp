#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>
struct edge
{
    int v, r;
};

vector<vector<edge>> G;


void solve()
{

    int n, m;
    cin >> n >> m;
    G = vector<vector<edge>>(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, 0});
        G[v].push_back({u, 1});
    }
    deque<int> dq;
    dq.push_back(1);
    int level = 0;
    vi vis(n + 1);
    while (!dq.empty())
    {
        int sz = dq.size();
        while (sz--)
        {
            int node = dq.front();
            dq.pop_front();
            if (vis[node])
                continue;
            vis[node] = 1;
            if (node == n)
            {
                cout << level << endl;
                return;
            }
            for (auto u: G[node])
            {
                if (u.r == 0)
                    dq.push_front(u.v), sz++;
                else dq.push_back(u.v);
            }
        }
        level++;
    }
    cout<<-1<<endl;
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