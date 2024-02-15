#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

string ops;

bool vis[7][7];
int ans;
bool b1, b2, b3, b4;
inline bool valid(int i, int j)
{
	return i >= 0 && i < 7 && j >= 0 && j < 7;
}
inline bool check(int i, int j)
{
	if (valid(i, j))
	{
		b1 = valid(i + 1, j + 0) && !vis[i + 1][j + 0];
		b2 = valid(i - 1, j + 0) && !vis[i - 1][j + 0];
		b3 = valid(i + 0, j + 1) && !vis[i + 0][j + 1];
		b4 = valid(i + 0, j - 1) && !vis[i + 0][j - 1];
		return !((b1 && b2 && !b3 && !b4) || (!b1 && !b2 && b3 && b4));
	}
	return false;
}
void rec(int x, int y, int i)
{
	if (vis[x][y])
		return;
	if (i == 48)
	{
		ans += ((x == 6) && (y == 0));
		return;
	}
	if (x == 6 && (y == 0 || (y == 6 && vis[6][5])))
		return;
	if (x == 5 && y == 1 && (!vis[5][0] && !vis[6][1]))
		return;

	vis[x][y] = true;
	if (ops[i] == '?')
	{
		if (check(x + 1, y))
			rec(x + 1, y, i + 1);

		if (check(x - 1, y))
			rec(x - 1, y, i + 1);

		if (check(x, y + 1))
			rec(x, y + 1, i + 1);

		if (check(x, y - 1))
			rec(x, y - 1, i + 1);

	}
	else if (ops[i] == 'D' && check(x + 1, y))
		rec(x + 1, y, i + 1);
	else if (ops[i] == 'U' && check(x - 1, y))
		rec(x - 1, y, i + 1);
	else if (ops[i] == 'L' && check(x, y - 1))
		rec(x, y - 1, i + 1);
	else if (ops[i] == 'R' && check(x, y + 1))
		rec(x, y + 1, i + 1);

	vis[x][y] = false;
}
void solve()
{
// code
	cin >> ops;
	auto start = chrono::high_resolution_clock::now();
	rec(0, 0, 0);
	cout << ans << endl;

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
	cerr << "Time taken :" << ((long double)duration.count()) / ((long double)1e9) << " s" << endl;
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