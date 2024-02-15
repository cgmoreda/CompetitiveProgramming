#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;

map<int, int> col, row, sum, dif;
char grid[8][8];

int ans = 0;
void solve(int i = 0)
{
	if (i == 8)
	{
		ans++;
		return;
	}
	if (!row[i])
		for (int j = 0; j < 8; j++)
			if (grid[i][j] == '.' && !col[j] && !sum[i + j] && !dif[i - j])
			{
				col[j] = row[i] = sum[i + j] = dif[i - j] = 1;
				solve(i + 1);
				col[j] = row[i] = sum[i + j] = dif[i - j] = 0;
			}

}
int main()
{
	for (auto & i : grid)
		for (char & j : i)
			cin >> j;

	solve();
	cout << ans << endl;
}