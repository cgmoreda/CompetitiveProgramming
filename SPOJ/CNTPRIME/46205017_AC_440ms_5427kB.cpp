#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long

#define outofrange l > e || s > r
#define inrange l <= s && e <= r
#define lchild p * 2, s, (s+e)/2
#define rchild p * 2 + 1, (s+e)/2 + 1, e
const int Nmax = 1e5 + 500;
int seg[4 * Nmax], lz[4 * Nmax];
int n, m, l, r, val;

void push(int p, int s, int e)
{
	if (!lz[p])
		return;
	seg[p] = (e - s + 1) * (lz[p] - 1);
	if (s != e)
		lz[p * 2 + 1] = lz[p],
			lz[p * 2] = lz[p];
	lz[p] = 0;

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

bool prime(long long x)
{
	if (x < 2)return false;
	if (x % 2 == 0)return x == 2;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)return false;
	}
	return true;
}

void solve()
{

	int t;
	cin >> n >> m;
	for (int i = 1; i <= 4 * n; i++)
		seg[i] = lz[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		l = r = i, val = 1 + prime(t);
		update();
	}
	while (m--)
	{
		cin >> t >> l >> r;
		if (t)
			cout << get() << endl;
		else
		{
			cin >> val;
			val = 1 + prime(val);
			update();
		}
	}
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, z = 1;
	cin >> t;
	for (z = 1; z <= t; z++)
	{
		cout << "Case " << z << ":\n";
		solve();
	}
}