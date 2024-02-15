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

bool prime(long long x)
{
	if (x < 2)return false;
	if (x % 2 == 0)return x == 2;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)return false;
	}
	return true;
}
void solve()
{

	int n;
	int a1, a2;
	cin >> n >> a1;
	for (int i = a1+1; true; i++)
	{
		if (prime(i))
		{
			a2 = i - a1;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
			cout << a1 << " ";
		else
			cout << a2 << " ";
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