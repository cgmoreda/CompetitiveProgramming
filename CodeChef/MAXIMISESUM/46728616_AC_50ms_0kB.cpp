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
	int n;
	cin >> n;
	vector<int> v(n);
	vin(v);
	int mx = *max_element(all(v));
	int cnt = 0, cmx = v[0], ans = 0;
	for (int i = 0; i < n; i++)
	{
		cnt++;
		cmx = max(cmx, v[i]);
		ans += cmx;
		if (v[i] == mx)
			break;
	}
	reverse(all(v));
	cmx = v[0];
	for (int i = 0; i < n; i++)
	{
		cnt++;
		cmx = max(cmx, v[i]);
		ans += cmx;
		if (v[i] == mx)
			break;
	}
	cout << ans + (n - cnt) * mx << endl;
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