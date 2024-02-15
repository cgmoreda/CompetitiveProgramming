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
	int n, k;
	cin >> n >> k;

	vector<int> v(k);
	vin(v);
	int ans = 0;
	for (int mask = 1; mask < (1 << k); mask++)
	{
		int prod = 1, cnt = 0;
		for (int i = 0; i < k; i++)
		{
			if (mask & (1 << i))
			{
				if (prod > 2 * n / v[i])
				{
					cnt = -1;
					break;
				}
				prod *= v[i];
				cnt++;
			}
		}
		if (cnt != -1)
		{
			if (cnt & 1)
			{
				ans += n / prod;
			}
			else
				ans -= n / prod;
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