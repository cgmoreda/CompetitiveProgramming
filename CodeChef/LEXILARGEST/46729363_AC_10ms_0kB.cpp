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
	int n, m;
	cin >> n >> m;
	vector<int> agcd(n);
	vin(agcd);
	int z = 1;
	int pr = 1;
	for (auto i : agcd)
	{
		if (z == 1)
		{
			cout << i << " ";
			z = 2;
		}
		else
		{
			int tmpo = m - m % i;
			while (gcd(tmpo, pr) != i)
				tmpo -= i;
			cout << tmpo << " ";
		}
		pr = i;
	}
	cout << endl;
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