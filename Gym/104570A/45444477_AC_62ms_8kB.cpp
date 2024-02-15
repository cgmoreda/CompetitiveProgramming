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
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	if (n / 100 > c)
	{
		n -= c * 100;
	}
	else
	{
		n %= 100;
	}
	if (n / 10 > b)
	{
		n -= b * 10;
	}
	else
	{
		n %= 10;
	}
	if (n <= a)
	{
		cout << "YES\n";
	}
	else cout << "NO\n";

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