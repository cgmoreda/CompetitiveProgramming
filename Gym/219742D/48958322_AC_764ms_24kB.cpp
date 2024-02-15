#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &h:(v))cin>>h
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long

bool lessr(deque<char>& a, deque<char>& b)
{
	if (a.size() == 0)
		return true;
	for (int i = 0; i < b.size(); i++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return false;
}

bool equals(deque<char>& a, deque<char>& b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < b.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
}

deque<char> maxs(deque<char> x)
{
	deque<char> y = x;
	for (int i = 0; i <= x.size(); i++)
	{
		y.push_back(y.front());
		y.pop_front();
		if (lessr(x, y))
			x = y;
	}
	return x;
}
void solve()
{
	int n;
	cin >> n;
	deque<char> last;
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		deque<char> x;
		string in;
		cin >> in;
		for (auto& kj : in)
			x.push_back(kj);

		if (!ok)
			continue;
		if (i == 0)
		{
			x = maxs(x);
			last = x;
		}
		else
		{
			bool ok1 = false;
			deque<char> z = {};
			deque<char> y = x;
			for (int b = 0; b <= x.size(); b++)
			{
				y.push_back(y.front());
				y.pop_front();
				if (equals(y, last))
				{
					z = y, ok1 = true;
					break;
				}
				if ((lessr(y, last) && (lessr(z, y))))
					z = y, ok1 = true;
			}

			if (!ok1)
				ok = false;
			last = z;
		}

	}
	if (ok)
	{
		cout << "Yes\n";
	}
	else
		cout << "No\n";

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