#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long

void solve()
{
	int n, k;
	cin >> n;
	vector<int> a(n), w(n);
	vin(w);
	vin(a);

	vector<int> dp(n), ds(n);
	for (int i = 0; i < n; i++)
	{
		dp[i] = a[i] - w[i];
		if (i)dp[i] = max(dp[i], dp[i - 1] - w[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		ds[i] = a[i] - w[i];
		if (i != n - 1)
			ds[i] = max(ds[i], ds[i + 1] - w[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int out = 0;
		if (i)
			out += dp[i - 1];
		if (i != n - 1)
			out += ds[i + 1];
		out = max(out - w[i], a[i] - w[i]);
		cout << out << " ";
	}
	cout << endl;
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