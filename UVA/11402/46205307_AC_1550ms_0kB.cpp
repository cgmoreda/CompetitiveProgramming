#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

#define outofrange l > e || s > r
#define inrange l <= s && e <= r
#define lchild p * 2, s, (s+e)/2
#define rchild p * 2 + 1, (s+e)/2 + 1, e
const int Nmax = 1e6 + 3e4;
int seg[4 * Nmax], lz[4 * Nmax];
string x;
int n, m, l, r, val;

void push(int p, int s, int e)
{
	if (!lz[p])
		return;
	if (lz[p] == 3)
		seg[p] = (e - s + 1) - seg[p];
	else
		seg[p] = (e - s + 1) * (lz[p] - 1);
	if (s != e)
	{
		if (lz[p] != 3)
			lz[p * 2 + 1] = lz[p], lz[p * 2] = lz[p];
		else
			lz[p * 2 + 1] ^= lz[p], lz[p * 2] ^= lz[p];
	}
	lz[p] = 0;

}
void build(int p = 1, int s = 1, int e = n)
{
	if (s == e)
	{
		seg[p] = x[s] == '1';
		return;
	}
	build(lchild), build(rchild);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
void update(int p = 1, int s = 1, int e = n)
{
	push(p, s, e);
	if (outofrange)return;
	if (inrange)
	{
		lz[p] = val;
		push(p, s, e);
		return;
	}
	update(lchild);
	update(rchild);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
int get(int p = 1, int s = 1, int e = n)
{
	push(p, s, e);
	if (outofrange)
		return 0;
	if (inrange)
		return seg[p];
	return get(lchild) + get(rchild);
}

void solve()
{
	x = "x";
	int t;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string y;
		cin >> t >> y;
		while (t--)
			x += y;
	}
	n = x.size();
	for (int i = 1; i <= 4 * n; i++)seg[i] = lz[i] = 0;

	build();
	char c;
	t = 1;
	cin >> m;
	while (m--)
	{
		cin >> c >> l >> r;
		l++, r++;
		if (c == 'F')
		{
			val = 2;
			update();
		}
		else if (c == 'E')
		{
			val = 1;
			update();
		}
		else if (c == 'I')
		{
			val = 3;
			update();
		}
		else if (c == 'S')
		{
			cout << "Q" << t++ << ": " << get() << endl;
		}
	}
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, z;
	cin >> t;
	for (z = 1; z <= t; z++)
	{
		cout << "Case " << z << ":\n";
		solve();
	}
}