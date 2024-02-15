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
const int N = 1e5;
int dp[N][3], n;
string x;
int dope(int i, int m3)
{
	if (i == n)
		return 0;

	int& ret = dp[i][m3];
	if (~ret)
		return ret;
	m3 = (m3 + x[i] - '0') % 3;
	return ret = (m3 == 0) + dope(i + 1, m3);

}
void solve()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += dope(i, 0);

	cout << ans << endl;
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