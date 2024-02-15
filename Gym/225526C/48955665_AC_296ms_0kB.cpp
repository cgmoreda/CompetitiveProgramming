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

pair<int, int> dr[] = {{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }};

void solve()
{
	int n;
	cin >> n;
	int l = 0, r = 1e9, mid, ans = 0;
	auto calc = [&](int x)
	{
	  return (x) * (x - 1) / 2 + x * (x + 1);
	};
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (calc(mid) <= n)
		{
			l = mid + 1;
			ans = max(ans, mid);
		}
		else r = mid - 1;
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
	cin >> t;
	while (t--)
		solve();

}