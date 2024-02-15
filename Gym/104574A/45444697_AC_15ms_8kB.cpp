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
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int area1 = n * m * 2;
	int area2 = x * y;
	if (area1 >= area2)
	{
		cout << area1 - area2 << endl;
	}
	else cout << "IMPOSSIBLE\n";
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