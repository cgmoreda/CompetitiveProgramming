#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

int n;
void solve(int s = 0, const string& x = "")
{
	if (x.size() == n)
		cout << x << endl;
	else
		solve(0, x + char(s + '0')),
			solve(1, x + char(s ^ 1 + '0'));

}

int32_t
main()
{

	cin >> n;
	solve();

}