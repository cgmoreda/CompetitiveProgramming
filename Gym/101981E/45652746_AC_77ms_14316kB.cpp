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
int n, k;
string trans(string x)
{
	stack<pair<char, int>> st;
	for (auto i : x)
	{
		if (st.size() && st.top().first == i)
		{
			int cnt = st.top().second;
			st.pop();
			st.push({ i, cnt + 1 });
		}
		else
			st.push({ i, 1 });
		while (st.size() && st.top().second == k)
			st.pop();
	}
	string ret;
	while (st.size())
		ret += string(st.top().second, st.top().first), st.pop();

	return ret;
}
void solve()
{
	cin >> n >> k;
	if (k == 1)
	{
		cout << "Yes\n";
		return;
	}
	string x, y;
	cin >> x >> y;
	x = trans(x);
	y = trans(y);
	cout << (x == y ? "Yes\n" : "No\n");

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

		solve();

}