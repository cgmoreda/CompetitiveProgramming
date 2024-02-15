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
	int x, y;
	cin >> n >> x >> y;
	int d1, d2, d3, d4;
	d1 = x - 1 + y - 1;
	d2 = n - x + y - 1;
	d3 = n - x + n - y;
	d4 = x + n - y - 1;
	int mn = min(min(d1, d2), min(d3, d4));
	// d1 d4
	// d2 d3
	if (d1 == mn)
	{
		cout << string(n - 1, 'U');
		cout << string(n - 1, 'L');
		cout << string(x - 1, 'D');
		cout << string(y - 1, 'R');
	}
	else if (d2 == mn)
	{
		cout << string(n - 1, 'D');
		cout << string(n - 1, 'L');
		cout << string(n - x, 'U');
		cout << string(y - 1, 'R');
	}
	else if (d3 == mn)
	{
		cout << string(n - 1, 'D');
		cout << string(n - 1, 'R');
		cout << string(n - x, 'U');
		cout << string(n - y, 'L');
	}
	else if (d4 == mn)
	{
		cout << string(n - 1, 'U');
		cout << string(n - 1, 'R');
		cout << string(n - y, 'L');
		cout << string(x - 1, 'D');
	}

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