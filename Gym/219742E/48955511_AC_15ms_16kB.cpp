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

pair<int, int> dr[] = {{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }};

void solve()
{
	int n;
	string x;
	cin >> x;
	n = x.size();
	for (int i = 0; i < n; i++)
	{
		if (x[i] == x[n - i - 1])
		{
			if (x[i] == '?')
			{
				x[i] = x[n - i - 1] = 'a';
			}
		}
		else if (x[i] == '?')
		{
			x[i] = x[n - i - 1];
		}
		else if (x[n - i - 1] == '?')
		{
			x[n - i - 1] = x[i];
		}
		else
		{
			cout << -1 << endl;
			return;
		}
	}
	cout << x << endl;
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