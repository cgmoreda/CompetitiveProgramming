#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

void solve(long long n)
{
	cout << n << " ";
	if (n == 1)
		return;
	else if (n & 1)
		solve((n * 3) + 1);
	else
		solve(n >> 1);
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;

	solve(t);

}