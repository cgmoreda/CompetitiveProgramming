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

bool can0(string x, int cnt1, int cnt0)
{
	if (cnt0 > cnt1)
		return true;
	if (x.empty())
		return 0;
	int n = x.size();
	stack<pair<char, int>> st;
	for (int i = 0; i < n; i++)
	{
		if (st.empty())
			st.push({ x[i], 1 });
		else
		{
			if (x[i] == '0' && st.top().first == '1')
			{
				int cnt = st.top().second;
				st.pop();
				if (cnt > 1)
					st.push({ '1', cnt - 1 });
			}
			else if (st.top().first != x[i])
				st.push({ x[i], 1 });
			else
			{
				int cnt = st.top().second;
				st.pop();
				st.push({ x[i], cnt + 1 });

			}
		}
		if (st.size() && st.top().first == '1' && st.top().second >= 3)
		{
			int cnt = st.top().second;
			st.pop();
			st.push({ x[i], cnt - 2 });
		}
	}
	cnt1 = 0, cnt0 = 0;
	while (st.size())
	{
		if (st.top().first == '1')
			cnt1 += st.top().second;
		else
			cnt0 += st.top().second;
		st.pop();
	}
	return cnt0 > cnt1;
}

bool can1(string x, int cnt1, int cnt0)
{
	if (cnt1 > cnt0)
		return true;
	for (auto& i : x)
		i = (i == '0' ? '1' : '0');
	return can0(x, cnt0, cnt1);
}
bool can01(string x, int cnt1, int cnt0)
{
	if (cnt0 == cnt1)
		return true;
	bool ok = false;
	if (cnt1 < cnt0)
		ok = true;
	int n = x.size();
	stack<pair<char, int>> st;
	for (int i = 0; i < n; i++)
	{
		if (ok)
			x[i] = (x[i] == '0' ? '1' : '0');
		if (st.empty())
			st.push({ x[i], 1 });
		else
		{
			if (x[i] == '0' && st.top().first == '1')
			{
				int cnt = st.top().second;
				st.pop();
				if (cnt > 1)
					st.push({ '1', cnt - 1 });
			}
			else if (st.top().first != x[i])
				st.push({ x[i], 1 });
			else
			{
				int cnt = st.top().second;
				st.pop();
				st.push({ x[i], cnt + 1 });

			}
		}
		if (st.size() && st.top().first == '1' && st.top().second >= 3)
		{
			int cnt = st.top().second;
			st.pop();
			st.push({ x[i], cnt - 2 });
		}
	}
	cnt1 = 0, cnt0 = 0;
	while (st.size())
	{
		if (st.top().first == '1')
			cnt1 += st.top().second;
		else
			cnt0 += st.top().second;
		st.pop();
	}
	return cnt0 >= cnt1;
}
int a[5050], n;
bool valid(int i)
{
	string l, r;
	int cnt1l = 0, cnt0l = 0, cnt1r = 0, cnt0r = 0;
	for (int j = 0; j < i; j++)
	{
		l += char((a[j] > a[i]) + '0');
		if (l.back() == '1')
			cnt1l++;
		else
			cnt0l++;
	}
	for (int j = i + 1; j < n; j++)
	{
		r += char((a[j] > a[i]) + '0');
		if (r.back() == '1')
			cnt1r++;
		else
			cnt0r++;
	}
	if ((can01(l, cnt1l, cnt0l) && can01(r, cnt1r, cnt0r)))
		return 1;
	if (can1(l, cnt1l, cnt0l) && can0(r, cnt1r, cnt0r))
		return 1;
	if ((can0(l, cnt1l, cnt0l) && can1(r, cnt1r, cnt0r)))
		return 1;
	return 0;
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cout << valid(i);
	cout << '\n';
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
		solve();;

}