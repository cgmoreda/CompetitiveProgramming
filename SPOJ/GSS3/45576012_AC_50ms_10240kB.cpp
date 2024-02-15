#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

#define int long long
const int inf = -1e9;
const int N = 5e4 + 100;
int nn, l, r, val;
int a[N];
struct rg
{
	int bc = -inf, bl = -inf, br = -inf, al = -inf;
	rg()
	{
	}
	rg(int v)
	{
		bc = bl = br = al = v;
	}
};
rg seg[N * 4];
rg proccess(rg a, rg b)
{
	rg x{};
	x.bl = max(a.bl, a.al + b.bl);
	x.br = max(b.br, b.al + a.br);
	x.al = a.al + b.al;
	x.bc = max(a.bc, b.bc);
	x.bc = max(x.bc, a.br + b.bl);
	return x;
}
struct segtree
{
	void build(int n = 1, int s = 1, int e = nn)
	{
		if (s == e)
		{
			seg[n] = (rg)a[s];
			return;
		}
		build(n * 2, s, (s + e) / 2);
		build(n * 2 + 1, (s + e) / 2 + 1, e);
		seg[n] = proccess(seg[n * 2], seg[n * 2 + 1]);
	}
	void update(int n = 1, int s = 1, int e = nn)
	{
		if (e < l || s > r)return;
		if (s == e)
		{
			seg[n] = val;
			return;
		}
		update(n * 2, s, (s + e) / 2);
		update(n * 2 + 1, (s + e) / 2 + 1, e);
		seg[n] = proccess(seg[n * 2], seg[n * 2 + 1]);
	}
	rg get(int n = 1, int s = 1, int e = nn)
	{
		if (e < l || s > r)return (rg)inf;
		if (s >= l && r >= e)return seg[n];
		return proccess(get(n * 2, s, (s + e) / 2), get(n * 2 + 1, (s + e) / 2 + 1, e));
	}
};

void solve()
{
	cin >> nn;
	for (int i = 1; i <= nn; i++)
		cin >> a[i];
	segtree sg;
	sg.build();
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		cin >> l >> r;
		if (type == 1)
		{
			rg tt = sg.get();
			int ans = max({ tt.bc, tt.br, tt.bl, tt.al });
			cout << ans << '\n';
		}
		else
		{
			val = r;
			r = l;
			sg.update();
		}
	}

}

int32_t main()
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