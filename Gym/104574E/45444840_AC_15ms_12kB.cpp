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
int n = 52;
vector<int> v(n);
void print()
{
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}
void shuffle(vector<int>& v)
{
	vector<int> ret;
	for (int i = 0; i < 26; i++)
	{
		ret.push_back(v[i]);
		ret.push_back(v[i + 26]);
	}
	v = ret;
}
void solve()
{
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int cnt = 16;
	// 8
	while (cnt--)
	{
		int c1 = 0;
		for (int i = 0; i < 26; i++)
			c1 += v[i] == 1;
		if (c1 == 4)
		{
			cout << "YES\n";
			return;
		}
		shuffle(v);
	}

	cout << "NO\n" << endl;
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