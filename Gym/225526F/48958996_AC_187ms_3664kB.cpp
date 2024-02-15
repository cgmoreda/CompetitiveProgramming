#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &h:(v))cin>>h
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

vector<vector<tuple<int, int, int>>> G;
//to_node value vis;
int id = 1;
bool bfs(int st, int ed, int bg)
{
	id++;
	queue<pair<int, int>> q;
	//{node,last value
	for (auto& [x, y, z] : G[st])
	{
		q.push({ x, y });
		z = id;
	}
	while (q.size())
	{
		auto [node, r] = q.front();
		q.pop();
		if (node == ed)
			return true;
		for (auto& [x, y, z] : G[node])
		{
			if (z != id && y <= r + bg && y >= r - bg)
			{
				q.push({ x, y });
				z = id;
			}
		}
	}
	return false;
}
void solve()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	G = vector<vector<tuple<int, int, int>>>(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({ v, w, 0 });
		G[v].push_back({ u, w, 0 });
	}
	int l = 0, r = 1e9, mid, ans = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (bfs(s, t, mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	cout << ans << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}