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
	int n;
	cin >> n;
	vector<int> v(n);
	vin(v);
	map<int, int> mp;
	for (auto i : v)mp[i]++;
	int ans = 0, ways1 = 1, way2 = n;
	for (int i = 0; i <= n; i++)
	{
		way2 -= mp[i];
		ans += i * ((ways1 * binpow(2, way2)) % mod) % mod;
		ans %= mod;
		ways1 *= binpow(2, mp[i]) - 1;
		ways1 %= mod;
		if (!mp.count(i))
			break;
	}
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