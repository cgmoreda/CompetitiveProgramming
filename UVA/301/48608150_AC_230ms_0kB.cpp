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
int ps[50];
int l[50], r[50], c[50];
int n, m, ts;
int ans;
void dope(int i, int earned)
{
	if (i >= ts)
	{
		ans = max(ans, earned);
		return;
	}

	bool ok = true;
	for (int j = l[i]; j < r[i]; j++)
	{
		ps[j] += c[i];
		if (ps[j] > n)
			ok = false;
	}
	if (ok)
		dope(i + 1, earned + c[i] * (r[i] - l[i]));

	for (int j = l[i]; j < r[i]; j++)
		ps[j] -= c[i];

	dope(i + 1, earned);

}
int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n >> m >> ts && (n != 0 || m != 0 || ts != 0))
	{
		for (int i = 0; i < ts; i++)
			cin >> l[i] >> r[i] >> c[i];
		ans = 0;
		dope(0, 0);
		cout << ans << endl;

	}

}
