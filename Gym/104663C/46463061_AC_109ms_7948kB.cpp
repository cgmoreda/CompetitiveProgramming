#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda
// ac
using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

vector<int> col;
int n, m;
const int N = 1001;
int dp[N][N];
int dope(int i, int pr)
{
	if (pr < 0 || pr == n)
		return 1e9;
	if (i == m)
		return 0;

	int& ret = dp[i][pr];
	if (~ret)
		return ret;

	ret = abs(col[i] - pr) + dope(i + 1, pr);
	ret = min(ret, abs(col[i] - (pr + 1)) + dope(i + 1, pr + 1));
	ret = min(ret, abs(col[i] - (pr - 1)) + dope(i + 1, pr - 1));
	return ret;
}
void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	col = vi(m);
	for (int i = 0; i < n; i++)
		for (int c, j = 0; j < m; j++)
		{
			cin >> c;
			if (c)
				col[j] = i;
		}

	int ret = 1e9;
	for (int i = 0; i < n; i++)
		ret = min(ret, abs(i - col[0]) + dope(1, i));
	cout << ret << endl;

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}