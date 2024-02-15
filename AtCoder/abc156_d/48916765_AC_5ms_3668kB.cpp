#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int modinv(int x)
{
	return binpower(x, mod - 2);
}
int nCr(int n, int r)
{
	r = min(r, n - r);
	int num = 1, denom = 1;
	for (int i = 1; i <= r; i++)
		denom = denom * i % mod;
	for (int i = n; i > (n - r); i--)
		num = num * (i) % mod;
	return num * modinv(denom) % mod;
}
void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	cout << (((binpower(2, n) - 1) - nCr(n, a) - nCr(n, b)) % mod + mod)%mod;
}
signed main()
{
	solve();

}
