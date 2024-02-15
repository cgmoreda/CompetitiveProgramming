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

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vin(a);
	vin(b);
	int bn = b.back();
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1], b[i] += b[i - 1];
	int best = -1e18;
	for (int i = 0; i < n; i++)
	{
		// bob takes 1;
		int alx = a[n - 1] - (i ? a[i - 1] : 0);
		int blx = b[n - 1] - b[i];
		int tmp = alx - b[n - 2];
		if (i != n - 1)
			tmp = min(tmp, (alx - bn) - blx);
		best = max(best, tmp);
	}
	cout << best << endl;
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