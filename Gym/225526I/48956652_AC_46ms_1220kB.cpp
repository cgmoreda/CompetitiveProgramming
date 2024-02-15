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

void solve()
{

	int n, m;
	cin >> n >> m;
	vector<int> c(n), f(m);
	vin(c);
	vin(f);
	sort(all(f));
	sort(all(c));
	int ans = 0;
	while (c.size() && f.size())
	{
		while (c.size() && c.back() > f.back())
			c.pop_back();
		if (c.size())
		{
			ans += c.back();
			c.pop_back();
			f.pop_back();
		}
	}
	cout << ans << endl;

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}