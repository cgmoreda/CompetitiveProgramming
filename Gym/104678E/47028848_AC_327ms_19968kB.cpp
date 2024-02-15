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
bool comp(ii a, ii b)
{
	return a.second < b.second;
}
void solve()
{

	set<int> s;
	int n, t = 0, ans = 0;
	cin >> n;
	vector<int> v(n);
	vin(v);
	map<int, int> mp;
	for (auto i : v)
	{
		s.insert(i);
		mp[i]++;
	}
	for (int i = 0; i < 2e9;)
	{
		if (mp.count(i))
			t += mp[i];
		if (t == 0)
		{
			if (s.lower_bound(i) != s.end())
				i = *s.lower_bound(i);
			else break;
			continue;
		}
		else
		{
			t--;
			i++;
			ans += t;
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