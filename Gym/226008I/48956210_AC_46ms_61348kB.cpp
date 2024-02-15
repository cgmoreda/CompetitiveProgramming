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

int dp[2590][55][55], a[55];

int n, m;
int ans = 0;
int dope(int i, int cnt, int sum)
{
	if (i == n)
	{
		if (cnt && sum / cnt == m && sum % cnt == 0)
			return 1;
		return 0;
	}
	if (~dp[sum][cnt][i])
		return dp[sum][cnt][i];
	else
		return dp[sum][cnt][i] = dope(i + 1, cnt + 1, sum + a[i]) + dope(i + 1, cnt, sum);
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];

	cout << dope(0, 0, 0) << endl;
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