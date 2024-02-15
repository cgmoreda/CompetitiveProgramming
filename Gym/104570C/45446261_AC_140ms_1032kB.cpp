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
int calc(int x)
{
	if (x < 3)
		return 0;

	int ret = 0;
	for (int i = 3; i <= x; i++)
	{
		ret += x - i + 1;
	}
	return ret;
}
int calco(int x)
{
	if (x < 3)
		return 0;

	int ret = 0;
	for (int i = 3; i <= x; i += 2)
	{
		ret += x - i + 1;
	}
	return ret;
}

void solve()
{
	int n;
	cin >> n;
	string x;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (i < n - 1 && x[i] == x[i + 1])i++;
		ans += calc(i - j + 1);
	}

	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (i < n - 1 && x[i] != x[i + 1])i++;

		ans += calco(i - j + 1);
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