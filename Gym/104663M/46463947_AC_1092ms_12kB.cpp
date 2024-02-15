#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
// ac
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
	int n, xmx, a, c;
	cin >> n >> xmx >> a >> c;
	bool state = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (state == 0)
		{
			if (x > xmx)
				cnt++;
			else cnt = 0;
			if (cnt == a)
			{
				state = 1;
				cnt = 0;
			}
		}
		else if (state == 1)
		{
			ans++;
			if (x <= xmx)
				cnt++;
			else
				cnt = 0;
			if (cnt == c)
			{
				state = 0;
				cnt = 0;
			}
		}
	}

	cout << ans + state << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)solve();

}