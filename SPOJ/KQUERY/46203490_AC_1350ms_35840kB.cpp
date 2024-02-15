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
const int N = 4e4;
int fen[N], a[N], n;
struct fenwik_tree
{
	int sum(int p)
	{
		int s = 0;
		while (p >= 1)
			s += fen[p], p -= p & -p;
		return s;
	}
	int sum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
	void add(int p, int x)
	{
		while (p <= n)
			fen[p] += x, p += p & -p;
	}
};
struct query
{
	int l, r, k;
};
void solve()
{
	fenwik_tree ft;
	cin >> n;
	map<int, vector<int>> idx;
	set<int> vals;
	vals.insert(2e9);
	for (int i = 1; i <= n; i++)
	{
		ft.add(i, 1);
		cin >> a[i];
		vals.insert(a[i]);
		idx[a[i]].push_back(i);
	}
	int m;
	cin >> m;
	vector<query> oj(m);
	map<int, vector<pair<int, int>>> qq;
	map<pair<int, pair<int, int>>, int> ans;
	for (int i = 0; i < m; i++)
	{
		cin >> oj[i].l >> oj[i].r >> oj[i].k;
		qq[*vals.upper_bound(oj[i].k)].push_back({ oj[i].l, oj[i].r });
	}
	for (auto v : vals)
	{
		for (auto& [l, r] : qq[v])
			ans[{ v, { l, r }}] = ft.sum(l, r);
		for (auto i : idx[v])
			ft.add(i, -1);
	}

	for (auto& [l, r, k] : oj)
		cout << ans[{ *vals.upper_bound(k), { l, r }}] << '\n';

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