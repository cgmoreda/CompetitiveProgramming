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
bool comp(ii a, ii b)
{
	return a.second < b.second;
}
void solve()
{

	string x;
	cin >> x;
	vector<int> out;
	out = { -2 };
	if (x.find('c') != string::npos)
	{
		int c = x.find('c');
		if (x.find('a', c) != string::npos)
		{
			int a = x.find('a', c);
			if (a != x.size() - 1)
				out = { c, a, a + 1 };
		}
		if (c + 2 < x.size() && x.find('t', c + 2) != string::npos)
		{
			int t = x.find('t', c + 2);
			out = { c, c + 1, t };
		}
	}
	if (x.find('a', 1) != string::npos)
	{
		int a = x.find('a', 1);
		if (a + 1 < x.size() && x.find('t', a + 1) != string::npos)
		{
			int t = x.find('t', a + 1);
			out = { 0, a, t };
		}
	}
	for (auto i : out)
		cout << i + 1 << " ";
	cout << endl;

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