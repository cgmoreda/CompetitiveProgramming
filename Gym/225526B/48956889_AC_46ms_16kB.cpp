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

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vin(a);
	vector<vector<int>> G(n);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int v;
			cin >> v;
			v--;
			G[i].push_back(v);
		}
	}
	int ans = 1e18;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		vector<int> vis(n);
		int cost = 0;
		for (int j = 0; j < n; j++)
		{
			if (mask & (1 << j))
			{
				vis[j] = 1;
				for (auto i : G[j])
					vis[i] = 1;
				cost += a[j];
			}
		}
		if (count(all(vis), 1) == n)
			ans = min(ans, cost);
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