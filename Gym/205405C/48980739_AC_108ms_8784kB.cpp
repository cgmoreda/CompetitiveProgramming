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
bool match(vvi a, vvi b)
{
	if (a.size() != b.size()
		|| a[0].size() != b[0].size())
		return false;
	set<int> s;
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
			s.insert(a[i][j] + b[i][j]);
	return s.size() == 1;
}
void rotate(vvi& a)
{
	vvi b(a[0].size(), vi(a.size()));

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
			b[j][i] = a[i][a[0].size() - 1 - j];
	a = b;
}
void print(vvi& a)
{
	for (auto i : a)
	{
		for (auto j : i)
			cerr << j << " ";
		cerr << endl;
	}
	cerr << endl;
}
void solve()
{

	int n1, m1;
	cin >> n1 >> m1;
	vector<vector<int>> b1(n1, vector<int>(m1));
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
			cin >> b1[i][j];
	int n2, m2;
	cin >> n2 >> m2;
	vector<vector<int>> b2(n2, vector<int>(m2));
	for (int i = 0; i < n2; i++)
		for (int j = 0; j < m2; j++)
			cin >> b2[i][j];

	for (int i = 0; i < 4; i++)
	{
		rotate(b1);
		//print(b1);
		//print(b2);
		cerr << "____\n";
		if (match(b1, b2))
		{
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}