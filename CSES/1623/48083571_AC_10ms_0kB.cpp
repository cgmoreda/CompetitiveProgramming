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
int n;
int a[21];
int rec(int k, int sum)
{
	if (k == n)
		return abs(sum);
	return min(rec(k + 1, sum + a[k]), rec(k + 1, sum - a[k]));
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << rec(0, 0) << endl;
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