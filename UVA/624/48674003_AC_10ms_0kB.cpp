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

int n, m;
int t[21];
vector<int> ans;
vector<int> cur;
int sol = -1;
void dope1(int i, int clenth)
{
	if (clenth > n)
		return;
	if (i == m)
	{
		if (sol == -1 || n - clenth < sol)
			ans = cur, sol = n - clenth;
		return;
	}
	dope1(i + 1, clenth);
	cur.push_back(t[i]);
	dope1(i + 1, clenth + t[i]);
	cur.pop_back();
}
void solve()
{
	sol = -1;
	ans.clear();
	for (int i = 0; i < m; i++)
		cin >> t[i];
	dope1(0, 0);
	for (auto i : ans)
		cout << i << " ";
	cout << "sum:" << accumulate(all(ans), 0LL) << endl;

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n >> m)
		solve();

}