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
vector<pair<int, int>> proccess(vector<pair<int, int>> rg)
{
	vector<ii > ret;
	ret.push_back({ 0, 0 });
	sort(all(rg));
	for (auto& i : rg)
	{
		if (i.first <= ret.back().second)
			ret.back().second = max(ret.back().second, i.second);
		else
			ret.push_back(i);
	}
	return ret;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> rg;
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		rg.push_back({ l, r });
	}
	rg.push_back({ 0, 0 });
	rg.push_back({ n + 1, n + 1 });
	rg = proccess(rg);
	int ans = 0;
	for (int i = 0; i < rg.size() - 1; i++)
	{
		int tmp = rg[i + 1].first - rg[i].second - 1;
		ans += tmp * (tmp + 1) / 2;
	}
	cout << ans << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << "KUET WOOD\n";
	return 0;
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}