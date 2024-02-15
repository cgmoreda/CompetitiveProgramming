#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const int inf = 2e9;
const int N = 1e5 + 100;
int n, l, r, val;
long long seg[N * 4], a[N];

struct segtree
{
	void build(int n, int s, int e)
	{
		if (s == e)
		{
			seg[n] = a[s];
			return;
		}
		build(n * 2, s, (s + e) / 2);
		build(n * 2 + 1, (s + e) / 2 + 1, e);
		seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
	}
	void update(int n, int s, int e)
	{
		if (e < l || s > r)return;
		if (s == e)
		{
			seg[n] = val;
			return;
		}
		update(n * 2, s, (s + e) / 2);
		update(n * 2 + 1, (s + e) / 2 + 1, e);
		seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
	}
	int get(int n, int s, int e)
	{
		if (e < l || s > r)return inf;
		if (s >= l && e <= r)return seg[n];
		return min(get(n * 2, s, (s + e) / 2), get(n * 2 + 1, (s + e) / 2 + 1, e));
	}
};

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	segtree st;
	st.build(1, 1, n);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		l++;
		r++;
		cout << st.get(1, 1, n) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}

}