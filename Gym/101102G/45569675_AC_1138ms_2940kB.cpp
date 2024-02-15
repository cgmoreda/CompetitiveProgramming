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

int n, m;
vector<int> v, ans;

bool can(int one, int five, int ten, int twent)
{
	int fif = n - one - five * 5 - ten * 10 - twent * 20;
	if (fif % 50)
		return false;
	fif /= 50;

	for (auto j : v)
	{
		int i = 0;
		int x = j - i * 50;
		if (x >= 0)
		{
			x -= min(x / 20, twent) * 20;
			x -= min(x / 10, ten) * 10;
			x -= min(x / 5, five) * 5;
			if (x <= one)
				goto next;
		}

		for (i = min(fif, j / 50); i > 0; i--)
		{
			x = j - i * 50;

			x -= min(x / 20, twent) * 20;
			x -= min(x / 10, ten) * 10;
			x -= min(x / 5, five) * 5;
			if (x <= one)
				goto next;
		}
		return false;
	next:
		continue;
	}

	ans = { one, five, ten, twent, fif };
	return true;
}
int sum(vector<int>& tm)
{
	int one = tm[0];
	int five = tm[1];
	int ten = tm[2];
	int twent = tm[3];
	return one + five * 5 + ten * 10 + twent * 20;
}
void solve()
{
	ans.clear();
	cin >> n >> m;
	v = vi(m);
	vin(v);

	queue<vector<int>> q;
	q.push({ 0, 0, 0, 0 });
	map<vector<int>, int> vis;
	while (q.size())
	{
		vector<int> tm = q.front();
		q.pop();
		if (vis[tm] || sum(tm) > n)
			continue;
		vis[tm] = 1;
		int one = tm[0];
		int five = tm[1];
		int ten = tm[2];
		int twent = tm[3];
		if (can(one, five, ten, twent))
			break;
		q.push({ one + 1, five, ten, twent });
		q.push({ one, five + 1, ten, twent });
		q.push({ one, five, ten + 1, twent });
		q.push({ one, five, ten, twent + 1 });
	}
	for (auto i : ans)
		cout << i << " ";
	cout << endl;;

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