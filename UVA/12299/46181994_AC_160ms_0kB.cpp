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
const int N = 1e5 + 5;
int a[N];
int seg[4 * N];
int l, r, pos, val;
int def = 1e9;
int n, m;
struct st
{
	void build(int p = 1, int s = 1, int e = n)
	{
		if (s == e)
		{
			seg[p] = a[s];
			return;
		}
		build(2 * p, s, (s + e) / 2);
		build(2 * p + 1, (s + e) / 2 + 1, e);
		seg[p] = min(seg[2 * p], seg[2 * p + 1]);
	}
	int get(int p = 1, int s = 1, int e = n)
	{
		if (r < s || e < l)return def;
		if (l <= s && e <= r)return seg[p];
		return min(get(2 * p, s, (s + e) / 2), get(2 * p + 1, (s + e) / 2 + 1, e));
	}
	void update(int p = 1, int s = 1, int e = n)
	{
		if (r < s || e < l)return;
		if (s == e)
		{
			seg[p] = val;
			return;
		}
		if (pos <= (s + e) / 2)update(2 * p, s, (s + e) / 2);
		else update(2 * p + 1, (s + e) / 2 + 1, e);
		seg[p] = min(seg[2 * p], seg[2 * p + 1]);
	}
};

vector<int> getnums(string x)
{
	vector<int> ret;
	int num = 0;
	bool add = false;
	for (auto i : x)
	{
		if (i >= '0' && i <= '9')
		{
			add = true;
			num *= 10;
			num += i - '0';
		}
		else
		{
			if (add)
				ret.push_back(num);
			num = 0;
		}
	}
	return ret;
}
void solve()
{
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	st sj;
	sj.build();
	while (m--)
	{
		string in;
		cin >> in;
		if (in[0] == 's')
		{
			vector<int> nums = getnums(in);
			if (nums.size() <= 1)
				continue;
			int tmp = a[nums[0]];
			for (int i = 0; i < nums.size() - 1; i++)
				a[nums[i]] = a[nums[i + 1]];
			a[nums.back()] = tmp;

			for (auto i : nums)
			{
				l = r = pos = i, val = a[i];
				sj.update();
			}
		}
		else
		{
			vector<int> nums = getnums(in);
			l = nums[0], r = nums[1];
			cout << sj.get() << "\n";
		}
	}
	

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (cin >> n >> m && n)
		solve();

}