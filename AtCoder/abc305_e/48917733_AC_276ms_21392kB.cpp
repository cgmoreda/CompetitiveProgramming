#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> G(n + 1);
	vector<int> dis(n + 1, -1);
	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	priority_queue<pair<int, int> > pq;
	// {health,node}
	for (int i = 0; i < k; i++)
	{
		int u, h;
		cin >> u >> h;
		dis[u] = h;
		pq.push({ h, u });
	}
	while (pq.size())
	{
		int node = pq.top().second;
		int hl = pq.top().first;
		pq.pop();
		if (hl < dis[node] || hl == 0)
			continue;

		for (auto u : G[node])
		{
			if (hl - 1 > dis[u])
			{
				dis[u] = hl - 1;
				pq.push({ dis[u], u });
			}
		}
	}
	cout << n - (count(all(dis), -1) - 1) << endl;
	for (int i = 1; i <= n; i++)
		if (~dis[i])
			cout << i << " ";
	cout << endl;
}
signed main()
{
	solve();

}
