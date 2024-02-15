#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &h:(v))cin>>h
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

int l1, r1;
void brute()
{
	int cnt = 0;

	for (int x = l1; x <= r1; x++)
		for (int y = l1; y <= r1; y++)
		{
			if ((x * x * y + x + y) % (x * y * y + y + 7) == 0)
			{
				//	cout << x << " " << y << " theory1:" << y / 7 << " theory2: " << (1.0 * x / y) << endl;
				cnt++;
			}
		}
	cout << cnt << " bruted" << endl << endl;

}

int counttillR(int R, int L)
{
	int l = 1, r = 1e9, mid, ans = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (mid * mid * 7 <= R)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	ans -= (L - 1) / 7;
	if (R >= 11 && L == 1)
		ans++;
	if (R >= 49 && L == 1)
		ans++;
	return max(0ll, ans);
}
void solve()
{

	cout << counttillR(r1, l1) << endl;
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
	{
		cin >> l1 >> r1;
		solve();
		//brute();
	}

}