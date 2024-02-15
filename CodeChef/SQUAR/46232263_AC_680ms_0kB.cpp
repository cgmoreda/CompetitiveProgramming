#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long

const int N = 1e7 + 100;
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

vector<bool> sqr(N);
int calc(int x)
{

	int num = 1;
	for (auto j : primes)
	{
		if (j * j > x)
			break;
		int cnt = 0;
		while (x % j == 0)
			x /= j, cnt++;

		if (cnt & 1)
			num *= j;
	}
	if (x != 1)
		num *= x;

	return num != 1 ? num : -1;

}
void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vin(v);
	map<int, int> ans;

	int mx = 0;
	for (auto x : v)
	{

		if (!sqr[x])
			mx = 1;
		x = calc(x);
		if (~x)
			ans[x]++;

	}

	for (auto i : ans)
		mx = max(i.second, mx);
	cout << mx << '\n';
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	auto start = chrono::high_resolution_clock::now();

	sieve();
	for (int i = 0; i * i < N; i++)
		sqr[i * i] = 1;

	int t = 1;
	cin >> t;
	while (t--)
		solve();

}