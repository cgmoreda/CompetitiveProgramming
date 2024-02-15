#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
void print(int a, int b)
{
	cout << a << " " << b << '\n';
}
void p1(int x, int y)
{
	for (int i = x + 1; i <= n; i++)
	{
		print(i, y);
		print(i, y - 1);
	}
	print(x, y);
	print(x, y - 1);
}
void p2(int x, int y)
{
	for (int i = y + 1; i <= m; i++)
	{
		print(x, i);
		print(x - 1, i);
	}
	print(x, y);
	print(x - 1, y);
}
void p3()
{
	print(n, 2), print(n - 2, 1), print(n - 1, 3), print(n, 1);
	print(n - 2, 2), print(n, 3), print(n - 1, 1), print(n - 2, 3), print(n - 1, 2);
}

int32_t main()
{
	cin >> n >> m;
	if (n % 2 == 0)
	{
		for (int i = 2; i <= n; i += 2)
			p2(i, 1);

	}
	else if (m % 2 == 0)
	{
		for (int i = 2; i <= m; i += 2)
		{
			p1(1, i);
		}
	}
	else
	{
		for (int i = 2; i + 3 <= n; i += 2)
			p2(i, 1);

		p3();

		for (int i = 5; i <= m; i += 2)
			for (int j = 1; j <= 3; ++j)
			{
				print(n - 3 + j, i);
				print(n - 3 + j, i - 1);
			}

	}

}
