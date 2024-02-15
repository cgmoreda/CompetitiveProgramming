#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define ll long long

int vis[1 << 9][110][110];
void solve()
{
    int n, m;
    cin >> n >> m;
    int adj[102][102]{};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                adj[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b][a] = adj[a][b] = min(adj[a][b], c);
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int s;
    cin >> s;
    int to[9]{};
    map<int, int> sp;
    for (int i = 0; i < s; i++)
    {
        cin >> to[i];
        sp[to[i]] = i;
    }
    int s1, s2, tmask;
    cin >> s1 >> s2;
    if (sp.count(s1))
        tmask |= sp[s1];
    if (sp.count(s2))
        tmask |= sp[s2];
    priority_queue<pair<int, pair<int, ii >>, vector<pair<int, pair<int, ii>>>, greater<>> pq;
    // dis,mask,p1,p2;
    pq.push({0, {tmask, {s1, s2}}});

    while (pq.size())
    {
        int totaldis = pq.top().first;
        int mask = pq.top().second.first;
        int p1 = pq.top().second.second.first;
        int p2 = pq.top().second.second.second;

        pq.pop();
        if (mask == (1 << s) - 1)
        {
            cout << totaldis << endl;
            return;
        }
        if (vis[mask][p1][p2])
            continue;
        vis[mask][p1][p2] = 1;

        for (int i = 0; i < s; i++)
        {
            if (!(mask & (1 << i)))
            {
                int nmask = mask | (1 << i);
                pq.push({totaldis + adj[p1][to[i]], {nmask, {to[i], p2}}});
                pq.push({totaldis + adj[p2][to[i]], {nmask, {p1, to[i]}}});
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}