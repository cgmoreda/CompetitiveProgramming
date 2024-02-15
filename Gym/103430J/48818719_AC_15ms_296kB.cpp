#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
int n, k, x;
vector<int> a, b, c, d;
int dp[2020][10];
int dope(int i, int rate)
{
	if (i == n)
		return rate;

	if (rate <= x + k && rate >= x - k)
	{
		int& ret = dp[i][rate - x + k];
		if (~ret)
			return ret;
		return ret = max(
			dope(i + 1, rate + (d[i] ? a[i] : -b[i])),
			dope(i + 1, rate + (c[i] ? a[i] : -b[i]))
		);
	}
	else if (rate > x + k)
		return dope(i + 1, rate + (d[i] ? a[i] : -b[i]));
	else
		return dope(i + 1, rate + (c[i] ? a[i] : -b[i]));

}
void solve()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> x;
	a = b = c = d = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	cout << dope(0, x) << endl;
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