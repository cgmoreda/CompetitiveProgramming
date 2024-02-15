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

int n, m;
const int N = 1e5 + 500;
vector<vector<tuple<int, int, int>>> rt;
int dp[N], vis[N], x, id;
int dope(int i)
{
	if (i == m + 1)
		return 0;
	if (vis[i] == id)
		return dp[i];
	vis[i] = id;
	int& ret = dp[i];
	ret = 1e14;
	for (auto& [nr, t, c] : rt[i])
		if (t <= x)
			ret = min(ret, dope(nr + 1) + c);
	return ret;
}
void solve()
{
	cin >> n >> m;
	rt = vector<vector<tuple<int, int, int>>>(m + 1);
	for (int i = 0; i < n; i++)
	{
		int l, r, t, c;
		cin >> l >> r >> t >> c;
		if (l > r)
			swap(l, r);
		rt[l].push_back({ r, t, c });
	}
	int l = 0, r = 1e9, mid, ans;
	while (l <= r)
	{
		mid = (l + r) / 2;
		id++;
		x = mid;
		if (dope(1) < 1e12)
		{
			r = mid - 1;
			ans = mid;
		}
		else 
			l = mid + 1;
	}
	id++;
	x = ans;
	cout << ans << " " << dope(1) << endl;
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