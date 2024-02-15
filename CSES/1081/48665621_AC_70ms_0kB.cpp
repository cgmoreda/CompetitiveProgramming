#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
const int N = 1e6;
void solve()
{
	int n;
	cin >> n;
	vector<int> freq(N + 1);
	vector<int> v(n);
	for (auto& i : v)
		cin >> i, freq[i]++;
	sort(all(v));
	for (int i = v.back(); i >= 1; i--)
	{
		int c = 0;
		for (int j = i; j <= v.back(); j += i)
			c += freq[j];
		if (c >= 2)
		{
			cout << i << endl;
			return;
		}
	}

}

int32_t
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();

}