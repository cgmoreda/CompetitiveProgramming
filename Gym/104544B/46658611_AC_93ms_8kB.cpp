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
	int g1 = 0, g2 = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		g1 = gcd(g1, a);
	}

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		g2 = gcd(g2, b);
	}
	map<int, int> mp1, mp2;
	set<int> prs;
	for (int i = 2; i * i <= g1; i++)
	{
		while (g1 % i == 0)
		{
			prs.insert(i);
			mp1[i]++;
			g1 /= i;
		}
	}
	if (g1 != 1)
	{
		prs.insert(g1);
		mp1[g1]++;
	}
	g1 = g2;
	for (int i = 2; i * i <= g1; i++)
	{
		while (g1 % i == 0)
		{
			prs.insert(i);
			mp2[i]++;
			g1 /= i;
		}
	}
	if (g1 != 1)
	{
		prs.insert(g1);
		mp2[g1]++;
	}
	int ops = 0;
	int ok1 = 0, ok2 = 0;
	for (auto i : prs)
	{
		ok1 |= mp1[i] > mp2[i];
		ok2 |= mp1[i] < mp2[i];

	}
	cout << ok1 + ok2 << '\n';
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