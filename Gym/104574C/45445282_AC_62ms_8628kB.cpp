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
struct peng
{
	int s, c, id;
};

bool comp(peng a, peng b)
{
	if (a.s * b.c == b.s * a.c)
	{
		return a.id > b.id;
	}
	else return a.s * b.c > b.s * a.c;
}
void solve()
{
	int n;
	cin >> n;
	vector<peng> v(n);
	vector<int> a(n), b(n);
	vin(a);
	vin(b);
	for (int i = 0; i < n; i++)
	{
		v.push_back({ a[i], b[i], i + 1 });
	}
	sort(all(v), comp);
	cout << v[0].id << endl;
	cout << v[1].id << endl;
	cout << v[2].id << endl;
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