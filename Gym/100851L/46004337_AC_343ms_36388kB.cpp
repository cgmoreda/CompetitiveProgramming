#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

ll n, w;
vector<ll> v1, v2, h;
vector<ll> pr, sf, pref;
vector<ll> prev_mx(), next_mx();

struct binary_lift
{
	vector<vector<ll>> stable;
	vector<ll> v;
	int lv;
	static int LOG2(int x)
	{
		return 31 - __builtin_clz(x);
	}
	binary_lift(vector<ll>& val, vector<ll>& v0)
	{
		swap(n, w);

		v = v0;
		lv = LOG2(n) + 1;
		stable = vector<vector<ll>>(lv + 1, vector<ll>(n + 2));
		stable[0] = val;
		stable[0].push_back(0);
		for (int k = 1; k <= lv; k++)
			for (int i = 1; i <= n; i++)
				stable[k][i] = stable[k - 1][stable[k - 1][i]];

		swap(n, w);
	}

	int lift(int st, int val)
	{
		for (int k = lv; k >= 0; k--)
			if (v[stable[k][st]] < val)
				st = stable[k][st];
		st = stable[0][st];
		return st;
	}
};
ll countneed(int lx, int rx, int x, int y)
{
	ll need = y;
	need -= pref[rx] - pref[lx - 1];

	ll lenthl = x - lx, lenthr = rx - x;

	need += lenthl * (y - lenthl) + (lenthl * (lenthl - 1)) / 2;
	need += lenthr * (y - lenthr) + (lenthr * (lenthr - 1)) / 2;
	return need;
}
ll bs(int st, binary_lift& bl, binary_lift& br)
{
	ll l = h[st], r = 2e9, mid, ans = h[st];
	while (l <= r)
	{
		mid = (l + r) / 2;
		ll x = st, y = mid;
		ll lx = bl.lift(st, y - x), rx = br.lift(st, y + x);
		if (lx && rx)
		{
			ll need = countneed(lx + 1, rx - 1, x, y);
			if (need <= n)
			{
				l = mid + 1;
				ans = max(ans, mid);
			}
			else r = mid - 1;
		}
		else r = mid - 1;
	}
	return ans;
}
void solve()
{
	cin >> w >> n;
	pref = v1 = v2 = h = vector<ll>(w + 2);
	for (int i = 1; i <= w; i++)
	{
		cin >> h[i];
		v1[i] = h[i] - i, v2[i] = h[i] + i;
		pref[i] = h[i] + pref[i - 1];
	}
	pr = prev_mx(), sf = next_mx();
	binary_lift l(pr, v1), r(sf, v2);
	ll ans = 0;
	for (int i = 1; i <= w; i++)
		ans = max(ans, bs(i, l, r));
	cout << ans << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);
	solve();

}

vector<ll> prev_mx()
{
	vector<ll> pre;
	stack<ll> st;
	pre.push_back(0);
	st.push(0);
	v1[0] = 2e9;
	for (int i = 1; i <= w; i++)
	{
		while (v1[i] >= v1[st.top()])st.pop();
		pre.push_back(st.top());
		st.push(i);
	}
	return pre;
}
vector<ll> next_mx()
{
	stack<ll> st;
	st.push(0);
	vector<ll> suf;
	v2[0] = 2e9;
	for (int i = w; i > 0; i--)
	{
		while (v2[i] >= v2[st.top()])st.pop();
		suf.push_back(st.top());
		st.push(i);
	}
	suf.push_back(0);
	reverse(all(suf));
	return suf;
}
