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

	int n, k;
	cin >> n >> k;
	vector<int> stories(n);
	for (auto& i : stories)
		cin >> i;
	sort(all(stories));
	for (int i = 1; i < n; i++)
		stories[i] += stories[i - 1];
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		cout << upper_bound(all(stories), a) - stories.begin() << " ";
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