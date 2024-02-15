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
void solve()
{

	vector<int> primes;
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

	priority_queue<pair<int, ii >, vector<pair<int, ii > >, Compare> pq;

	pq.push({ 0, { a, b }});
	unordered_map<long long, bool> vis;
	while (pq.size())
	{
		int lv = pq.top().first;
		a = pq.top().second.first;
		b = pq.top().second.second;
		pq.pop();
		if (vis.count(cp(a, b)))
			continue;
		vis[cp(a, b)] = 1;
		if (a == 1 || b == 1)
		{
			cout << lv << endl;
			return;
		}
		pq.push({ lv + a - 1, { 1, 1 }});

		int df = b - a;
		for (auto i : primes)
			if (df % i == 0)
			{
				pq.push({ lv + a % i + 1, { a / i, b / i }});
				pq.push({ lv + i - a % i + 1, { a / i + 1, b / i + 1 }});
			}
	}
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