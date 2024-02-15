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
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

void solve()
{
	int x, y, k;
	cin >> x >> y >> k;

	while (x != y && k-- > 0)
	{
		if (x < y)
			swap(x, y);
		x = gcd(x, y);
	}
	cout << x + y << endl;
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