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

int p1, p2, q1, q2;
int qonly(int x)
{
	if (x <= 0)
		return 0;
	return ((x + q1 - 1) / q1) * q2;
}
int best(int x)
{
	return min(qonly(x), qonly(x - p1) + p2);
}
void solve()
{

	int xp, m;
	cin >> xp >> m;
	cin >> p1 >> p2;
	cin >> q1 >> q2;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		xp -= best(a);
	}
	if (xp > 0)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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