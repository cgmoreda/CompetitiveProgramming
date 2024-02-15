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
#define outofrange l > e || s > r
#define inrange l <= s && e <= r
#define lchild p * 2, s, (s+e)/2
#define rchild p * 2 + 1, (s+e)/2 + 1, e
const int N = 1e5 + 500;
int seg[4 * N], lz[4 * N];
int n, l, r, val;

void dostuff(int p, int s, int e)
{
	if (s != e)lz[p * 2] += lz[p], lz[p * 2 + 1] += lz[p];
	seg[p] += (e - s + 1) * lz[p], lz[p] = 0;
}
void update(int p = 1, int s = 1, int e = n)
{
	dostuff(p, s, e);
	if (outofrange)return;
	if (inrange)
	{
		lz[p] = val;
		dostuff(p, s, e);
		return;
	}
	update(lchild), update(rchild);
	seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
int get(int p = 1, int s = 1, int e = n)
{
	dostuff(p, s, e);
	if (outofrange)
		return 0;
	if (inrange)
		return seg[p];
	return get(lchild) + get(rchild);
}
void solve()
{
	int m, ty;
	cin >> n >> m;
	for (int i = 1; i <= 4 * n; i++)
		seg[i] = lz[i] = 0;
	while (m--)
	{
		cin >> ty >> l >> r;
		if (!ty)
		{
			cin >> val;
			update();
		}
		else cout << get() << endl;
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