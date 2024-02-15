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
	if (n % 5 != 0)
	{
		cout << "NO\n";
	}
	else
	{
		int cnt = 0;
		cnt += n / 15;
		n %= 15;
		cnt += n / 10;
		n %= 10;
		cnt += n / 5;
		cout << cnt << endl;
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