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

	int k, n;
	cin >> n >> k;
	vector<pair<int, int>> vp;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		vp.push_back({ a, b });
	}
	sort(all(vp), comp);
	int cnt = 0;
	int pr = -1;
	for (auto i : vp)
	{
		if (i.first >= pr)
			cnt++, pr = i.second;
	}
	cout << cnt << endl;
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