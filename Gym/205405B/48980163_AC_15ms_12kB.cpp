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

	string x;
	int lev = 1;
	map<int, int> mp;
	while (getline(cin,x))
	{
	          if (x.back() == '{')
		{
			lev++;
		}
		else if (x.back() == '}'&&x.find('f')==string::npos)
		{
			lev--;
		}
		else
		{
			mp[lev]++;
		}
	}
	int z = 0;
	for (auto [lv, cnt] : mp)
	{
		if (z)
			cout << " + ";
		z = 1;
		if (cnt > 1)
		{
			cout << cnt;
		}
		cout << 'N';
		if (lv > 1)
		{
			cout << "^" << lv;
		}
	}
	cout << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}