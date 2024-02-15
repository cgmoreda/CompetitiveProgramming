#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

const int N = 1e6 + 5;
const int lvls = 21;
vector<vector<int>> v(N);
int depth[N];
int dp[N][lvls + 1]; // log(N) powers of 2
int n;
int lca(int x, int y)
{
	if (depth[x] < depth[y])swap(x, y);
	for (int k = lvls; k >= 0; k--)
	{
		if (depth[x] - (1 << k) >= depth[y])
			x = dp[x][k];
	}
	if (x == y)return x;
	for (int k = lvls; k >= 0; k--)
	{
		if (dp[x][k] != dp[y][k])
			x = dp[x][k], y = dp[y][k];
	}
	return dp[x][0];
}
void dfs(int node, int par)
{
	dp[node][0] = par;
	depth[node] = depth[par] + 1;
	for (auto it : v[node])
	{
		if (it == par)continue;
		dfs(it, node);
	}
}
void process()
{
	for (int k = 1; k <= lvls; k++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[j][k - 1] == -1)continue;
			dp[j][k] = dp[dp[j][k - 1]][k - 1];
		}
	}
}
int mylog2(int x)
{
	if (!x)
		return x;
	return 63 - __builtin_clzll(x);
}
int goup(int node, int dis)
{
	while (dis)
	{
		int sz = mylog2(dis & -dis) ;
		node = dp[node][sz];
		dis &= dis - 1;
	}
	return node;
}
void solve()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(dp, -1, sizeof dp);
	dfs(0, n);
	process();
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		int l = lca(a, b);
		int dis1 = depth[a] - depth[l];
		int dis2 = depth[b] - depth[l];
		if (c >= dis1 + dis2)
			cout << b + 1 << "\n";
		else if (c > dis1)
			cout << goup(b, dis2 - (c - dis1)) + 1 << "\n";
		else if (c <= dis1)
			cout << goup(a, c) + 1 << "\n";
		cout << flush;
	}
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