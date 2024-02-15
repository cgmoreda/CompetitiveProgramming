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
const int N = 1e5 + 500;
int dp[N][55][3];
int n;
int a[N];
int dope(int i, int last, int state)
{
	if (i == n)
		return 0;

	int& ret = dp[i][last + 1][state];
	if (~ret)
		return ret;
	ret = dope(i + 1, last, state);
	if (state)
	{
		if (a[i] > last)
			ret = max(ret, dope(i + 1, a[i], 0) + 1);
	}
	else
	{
		if (a[i] < last)
			ret = max(ret, dope(i + 1, a[i], 1) + 1);
	}
	return ret;
}

void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << max(dope(0, -1, 1),dope(0, 51, 0));
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