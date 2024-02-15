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
	vector<int> idxb(n + 1);
	for (int i = 0; i < n; i++)
		idxb[b[i]] = i;
	vector<int> vis(n + 1);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		int j = idxb[a[i]];
		for (; i < n && j < n && b[j] == a[i];)
		{
			cnt++;
			if (i < n && j < n && b[j + 1] == a[i + 1])
				i++, j++;
			else
				break;
		}
		if (cnt >= 2)
			ans++;
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