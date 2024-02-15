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

int dp[101][101][101], a[101];

int n, d, m;

int dope(int i, int prev, int left)
{
	if (i == n)
		return 0;

	int& ret = dp[i][prev][left];

	if (~ret)
		return ret;

	if (i == 0)
		prev = a[i];
	ret = dope(i + 1, a[i], left) + abs(a[i] - prev);
	if (left)
	{
		int x;
		for (int j = 1; j <= left; j++)
		{
			x = a[i] - j;
			if (x <= 0)
				break;
			if (i == 0)
				prev = x;
			ret = max(ret, dope(i + 1, x, left - j) + abs(x - prev));
		}
		for (int j = 1; j <= left; j++)
		{
			x = a[i] + j;
			if (x > m)
				break;
			if (i == 0)
				prev = x;
			ret = max(ret, dope(i + 1, x, left - j) + abs(x - prev));
		}
	}
	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> d >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << dope(0, 0, d) << endl;
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