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
const int mod = 1e9 + 7;

const int NMAX = 2e6 + 500;
ll fact[NMAX], invfact[NMAX];
ll binPow(ll x, ll y)
{
	ll ans = 1;
	for (; y; y >>= 1, x = x * x % mod)
		if (y & 1)
			ans = ans * x % mod;
	return ans;
}
void fac()
{
	fact[0] = invfact[0] = 1;
	for (ll i = 1; i < NMAX; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = binPow(fact[i], mod - 2);
	}
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fac();

	vector<int> dp(NMAX);
	for (int i = 1; i < NMAX; i++)
		dp[i] = (dp[i - 1] * i % mod + fact[i - 1] * (i - 1) % mod) % mod;

	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}

}