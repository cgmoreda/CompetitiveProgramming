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
const int Nmax = 1e4 + 100;
int fr[Nmax], sc[Nmax];

void solve()
{
	int n, F, S;
	cin >> n >> F >> S;
	for (int i = 0; i < n; i++)
		cin >> fr[i] >> sc[i];

	vvi dp(F + 1, vi(S + 1, -1e18));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		vvi ndp(dp);
		for (int j = 0; j <= F; j++)
			for (int k = 0; k <= S; k++)
			{
				if (j)
					ndp[j][k] = max(ndp[j][k], dp[j - 1][k] + fr[i]);
				if (k)
					ndp[j][k] = max(ndp[j][k], dp[j][k - 1] + sc[i]);
			}
		dp = ndp;
	}
	int mx = 0;
	for (int j = 0; j <= F; j++)
		for (int k = 0; k <= S; k++)
			mx = max(mx, dp[j][k]);
	cout << mx << endl;
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