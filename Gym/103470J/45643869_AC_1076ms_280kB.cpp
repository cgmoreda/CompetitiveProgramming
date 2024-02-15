#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define ii pair<int,int>
#define ll long long
class Compare
{
 public:
	bool operator()(pair<int, ii > a, pair<int, ii > b)
	{
		return a.first > b.first;
	}
};
ll cp(ll a, ll b)
{
	return a | (b << 30);
}
vector<int> primes;
map<ll, int> vis;

int dope(int a, int b)
{
	if (a == 1 || b == 1) return 0;
	if (vis.count(cp(a, b))) return vis[cp(a, b)];
	int ret = a - 1;
	int dif = b - a;
	for (auto i : primes)
		if (dif % i == 0)
			ret = min({ ret, (1 + dope(a / i, b / i) + a % i), (1 + dope(1 + a / i, 1 + b / i) + i - a % i) });

	vis[cp(a, b)] = ret;
	return ret;
}
void solve()
{
	primes.clear();
	vis.clear();
	int a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	int dif = b - a;
	for (int i = 2; (ll)i * i <= dif; i++)
		if (dif % i == 0)
		{
			primes.push_back(i);
			while (dif % i == 0)
				dif /= i;
		}
	if (dif != 1)
		primes.push_back(dif);

	cout << dope(a, b) << '\n';
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