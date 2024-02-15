#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
// ac
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

int dp[1010][1010];
void solve()
{
	memset(dp, -1, sizeof dp);
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<vector<pair<int, int>>> G(n + 1), b(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		G[u].push_back({ v, t });
		b[v].push_back({ u, t * 2 });
	}
	priority_queue<pair<int, ii >, vector<pair<int, ii>>, greater<>> pq;
	pq.push({ 0, { 0, s }});
	vi mk(n + 1, 1e9), bdis(n + 1, 2e16);

	while (pq.size())
	{
		int dis = pq.top().first;
		int node = pq.top().second.second;
		int nr = pq.top().second.first;
		pq.pop();
		if (mk[node] <= nr || nr > k)
			continue;
		bdis[node] = min(bdis[node], dis);
		mk[node] = nr;
		for (auto&& [i, cost] : G[node])
		{
			if (mk[i] > nr)
				pq.push({ dis + cost, { nr, i }});
		}
		for (auto&& [i, cost] : b[node])
		{
			if (mk[i] > nr + 1)
				pq.push({ dis + cost, { nr + 1, i }});
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int d;
		cin >> d;
		if (bdis[d] > 1e16)
			cout << -1 << '\n';
		else
			cout << bdis[d] << '\n';
	}
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}