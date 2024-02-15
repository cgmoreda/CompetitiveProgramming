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
	string x;
	int n;
	cin >> n;
	cin >> x;
	stack<char> st;
	for (auto i : x)
	{
		if (i == ')')
		{
			if (st.empty())
			{
				cout << "NO\n";
				return;
			}
			else st.pop();
		}
		else st.push('(');
	}
	if (st.empty())
		cout << "YES\n";
	else
		cout << "NO\n";
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