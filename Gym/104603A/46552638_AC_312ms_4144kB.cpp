#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define vi vector<int>
#define int long long

inline int sq(int x)
{
	return x * x;
}

struct point
{
	int x, y;

	double dis(point a) const
	{
		return sqrt(sq(x - a.x) + sq(y - a.y));
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, int>> ms;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ms.push({ a, i });
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		while (ms.top().first >= a)
		{
			pair<int, int> tmp = ms.top();
			ms.pop();
			tmp.first %= a;
			ms.push(tmp);
		}
	}
	vi out(n);
	while (!ms.empty())
	{
		out[ms.top().second] = ms.top().first;
		ms.pop();
	}
	for (auto i : out)
		cout << i << " ";
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}