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

void solve()
{

	string a, b;
	cin >> a >> b;
	if (a.size() < b.size())
		swap(a, b);
	reverse(all(b));
	while (b.size() != a.size())
		b.push_back('0');
	reverse(all(a));
	vector<int> out;
	int car = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int n1 = a[i] - '0';
		int n2 = b[i] - '0';
		out.push_back((n1 + n2 + car) % 10);
		car = (n1 + n2 + car) / 10;
	}
	if (car)
		out.push_back(car);
	reverse(all(out));
	for (auto i : out)
		cout << i;
	cout << endl;

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