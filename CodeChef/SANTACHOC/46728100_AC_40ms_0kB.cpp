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
	vi v(n);
	vin(v);
	int sum = accumulate(all(v),0LL);
	if (k == 0)
	{
		cout << (sum && sum % n == 0 ? "YES\n" : "NO\n");
	}
	else
		cout << (sum >= n ? "YES\n" : "NO\n");
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