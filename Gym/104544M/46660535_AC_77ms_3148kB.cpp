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
long long binpow(long long x, long long k)
{
	long long ret = 1;
	while (k)
	{
		if (k & 1) ret = (ret * x) % mod;
		k >>= 1;
		x = (x * x) % mod;
	}
	return ret;
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	vin(v);
	vector<int> can_use(n, 1);
	int con = 0;
	for (int j = k - 1; j >= 0; j--)
	{
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			if ((1 << j) & v[i] || can_use[i])
			{

			}
			else ok = false;
		}
		if (ok)
		{
			con |= 1 << j;
			for (int i = 0; i < n; i++)
			{
				if ((1 << j) & v[i])
				{

				}
				else
				{
					can_use[i] = 0;
					v[i] |= 1 << j;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (can_use[i])
			if (__builtin_popcount(v[i]) == k && v[i] == con)
			{
				v[i] -= 1;
			}
	}
	int ans = v[0];
	for (auto i : v)
		ans &= i;
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