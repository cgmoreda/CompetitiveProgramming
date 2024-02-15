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
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

const int mod = 1e9 + 7;

long long binpower(long long x, long long k)
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

const int N = 1e6;
bool prime[N];
vector<int> primes;

void sieve()
{
	for (int i = 0; i < N; i++)
		prime[i] = 1;

	prime[0] = prime[1] = 0;
	for (int i = 4; i < N; i += 2)
	{
		prime[i] = 0;
	}
	for (int i = 3; i * i < N; i += 2)
	{
		if (prime[i])
		{
			for (int j = i * i; j < N; j += i + i)
			{
				prime[j] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
		if (prime[i])
			primes.push_back(i);
}
int cc(int p, int idx)
{
	return idx / p;
}
int count(int p, int l, int r)
{
	int cnt = cc(p, r) - cc(p, l - 1);
	return (cnt % mod + mod) % mod;
}
int get(int l, int r)
{
	int cnt = 0;
	for (int i = l; i <= r; i++)
		cnt += lcm(i, r) / i;

	return cnt;
}
int sum(int l, int r)
{
	return (r * (r + 1) / 2 - l * (l - 1) / 2) % mod;
}
void solve()
{
	int l, r;
	cin >> l >> r;
	cerr << "ans: " << get(l, r) << endl;
	int ans = sum(l, r) % mod * r % mod;
	int x = r;
	for (auto i : primes)
	{
		int j = i;
		while (x % j == 0)
		{
			int cnt = count(j, l, r);
			ans -= i * cnt;
			ans %= mod;
			j *= i;
		}
		j /= i;
		x /= j;
	}

	ans %= mod;
	cout << ans << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y, z, n;
	cin >> x >> y >> z >> n;
	int tc = x * y;
	int at = 0, can = x - z;

	can *= y;
	while (can >= at)
	{
		if ((n + at) * 100 / tc >= 60)
		{
			cout << "Yes\n";
			vector<int> v(x - z);
			for (auto& i : v)
			{
				i = min(at, y);
				at -= i;
			}
			reverse(all(v));
			for (auto i : v)cout << i << " ";
			cout << endl;
			return 0;
		}
		at++;
	}
	cout << "No\n";
	return 0;
	sieve();
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}