#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const ll mod = 1e9 + 7, N = 1e5 + 5;

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, k;
		cin >> u >> k;
		v[u]++, v[k]++;
	}
	char a = 'a', b = 'b';
	if (v[1] != 1)
		swap(a, b);
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 1)
			cout << a;
		else cout << b;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin>>t;
	while (t--)
		solve();

}
