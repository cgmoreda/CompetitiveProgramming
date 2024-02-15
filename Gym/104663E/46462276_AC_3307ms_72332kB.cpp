#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
// don't read my code
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

const int N = 3030;
vvi G;
int nv[N], p[N];
int n, m, r, q;
vector<int> mrg(vector<int>& a, vector<int>& b)
{
	vector<int> ret(N);
	vector<int> ass, ass2;
	for (int i = 0; i < N; i++)
	{
		if (a[i])ass.push_back(i);
		if (b[i])ass2.push_back(i);
		ret[i] = max(a[i], b[i]);
	}
	for (int i = 0; i < ass.size(); i++)
		for (int j = 0; j < ass2.size(); j++)
		{
			if (ass[i] + ass2[j] > 3000)
			{
				ret[3001] = 1;
				break;
			}
			ret[ass[i] + ass2[j]] = max(ret[ass[i] + ass2[j]], a[ass[i]] + b[ass2[j]]);
		}
	return ret;
}
vector<int> dfs(int node, int par)
{
	vector<int> ret(N);
	for (auto i : G[node])
		if (i != par)
		{
			vector<int> b = dfs(i, node);
			ret = mrg(ret, b);
		}
	for (int i = N - 1; i >= 0; i--)
	{
		if (i == 0 || ret[i])
		{
			if (p[node] + i <= 3000)
				ret[i + p[node]] = nv[node] + ret[i];
			else
				ret[3001] = 1;
			break;
		}
	}
	return ret;
}

void solve()
{
	cin >> n >> m >> r >> q;
	G = vvi(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> nv[i];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> bst = dfs(r, -1);
	for (int i = 1; i < N; i++)
		bst[i] = max(bst[i - 1], bst[i]);
	while (q--)
	{
		int c;
		cin >> c;
		cout << bst[c] << '\n';
	}

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1, z = 1;
	cin >> t;
	while (t--)
	{
		cout << "Case " << z++ << ":\n";
		solve();
	}

}