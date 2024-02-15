#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define path1 n*2,s,(s+e)/2
#define path2 n*2+1,(s+e)/2+1,e
const int N = 1e6 + 200;

int l, r, n;
struct range
{
	int tr, tl;
};
range seg[4 * N];
string x;
range match(range a, range b)
{
	range c{};
	c.tl = a.tl + max(0, b.tl - a.tr);
	c.tr = b.tr + max(0, a.tr - b.tl);

	return c;
}
void build(int n, int s, int e)
{
	if (s == e)
	{
		seg[n] = range({ x[s] == '(', x[s] == ')' });
		return;
	}
	build(path1);
	build(path2);
	seg[n] = match(seg[n * 2], seg[n * 2 + 1]);
}
range get(int n, int s, int e)
{
	if (e < l || s > r)return { 0, 0 };
	if (l <= s && e <= r)return seg[n];
	return match(get(path1), get(path2));
}
void update(int n, int s, int e)
{
	if (e < l || s > r)return;
	if (s == e)
	{
		swap(seg[n].tl, seg[n].tr);
		return;
	}
	update(path1);
	update(path2);
	seg[n] = match(seg[n * 2], seg[n * 2 + 1]);
}
int ans()
{
	l = 1;
	r = n;
	range hg = get(1, 1, n);
	return hg.tr || hg.tl;
}
void solve()
{

	cin >> n;
	string y;
	cin >> y;
	x = '0' + y;
	n = (int)x.size();
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--)
	{

		int idx;
		cin >> idx;
		if (idx)
		{
			l = r = idx;
			update(1, 1, n);
		}
		else
			cout << (!ans() ? "YES\n" : "NO\n");

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 10;
	//cin >> t;
	while (t--)
	{
		cout << "Test " << 10 - t << ":\n";
		solve();
		cout << flush;
	}

}