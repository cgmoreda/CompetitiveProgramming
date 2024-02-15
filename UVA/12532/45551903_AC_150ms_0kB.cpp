#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define path1 n*2,s,(s+e)/2
#define path2 n*2+1,(s+e)/2+1,e
const int N = 1e5 + 100;
int a[N], seg[4 * N];
int nn, m, idx, val, l, r;
void build(int n, int s, int e)
{
	if (s == e)
	{
		seg[n] = a[s];
		return;
	}
	build(path1);
	build(path2);
	seg[n] = seg[n * 2] * seg[n * 2 + 1];
}
void update(int n, int s, int e)
{
	if (l > e || s > r)return;
	if (s == e)
	{
		seg[n] = val;
		return;
	}
	update(path1);
	update(path2);
	seg[n] = seg[n * 2] * seg[n * 2 + 1];
}
int get(int n, int s, int e)
{
	if (l > e || s > r)return 1;
	if (s >= l && e <= r)return seg[n];
	return get(path1) * get(path2);
}
void solve()
{
	for (int i = 1; i <= nn; i++)
	{
		cin >> a[i];
		if (a[i])
			a[i] /= abs(a[i]);
	}
	build(1, 1, nn);
	for (int i = 0; i < m; i++)
	{
		char ty;
		cin >> ty;
		if (ty == 'C')
		{
			cin >> idx >> val;
			l = idx;
			r = idx;
			if (val)
				val /= abs(val);
			update(1, 1, nn);
		}
		else
		{
			cin >> l >> r;
			int g = get(1, 1, nn);
			if (!g)
				cout << g;
			else
				cout << (g < 0 ? '-' : '+');
		}
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (cin >> nn >> m)
	{
		solve();
	}

}