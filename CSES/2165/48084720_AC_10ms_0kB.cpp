#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
vector<pair<int, int>> out;
void hanoi(int a, int b, int count)
{
	if (count == 0)
		return;
	int mid = 6 - a - b;
	hanoi(a, mid, count - 1);
	out.push_back({ a, b });
	hanoi(mid, b, count - 1);
}
void solve()
{

	int n;
	cin >> n;
	hanoi(1, 3, n);
	cout << out.size() << endl;
	for (auto i : out)
		cout << i.first << " " << i.second << "\n";
}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

}