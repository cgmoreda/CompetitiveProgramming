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
	vector<int> v(n + 1);
	vvi G(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		G[v[i]].push_back(i);
	}
	queue<int> q;
	q.push(1);
	vi vis(n + 1);
	vi dis(n + 1);
	int lev = 0;
	while (q.size())
	{
		int sz = q.size();
		while (sz--)
		{
			int node = q.front();
			q.pop();
			if (vis[node])
				continue;
			vis[node] = 1;
			dis[node] = lev;
			for (auto i : G[node])
				q.push(i);
		}
		lev++;
	}
	int cnt = 0, div = 0;
	for (int i = 1; i <= n; i++)
		if (vis[v[i]])
		{
			div += dis[v[i]] + 1;
			cnt++;
		}
	cout << fixed << setprecision(8);
	cout << double(div) / cnt - 1 << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();

}