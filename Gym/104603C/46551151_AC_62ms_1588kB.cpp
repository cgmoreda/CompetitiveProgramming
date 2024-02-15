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
	sort(all(a));
	sort(allr(b));
	for (int i = 0; i < n; i++)
		a[i] += b[i];
	sort(all(a));
	cout << a[n - 1] - a[0] << endl;
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