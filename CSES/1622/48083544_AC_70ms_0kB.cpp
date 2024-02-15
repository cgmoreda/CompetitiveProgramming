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
vector<string> out;
int cnt[150];
int n;
string s;
void rec(int k)
{
	if (k == n)
	{
		out.push_back(s);
		return;
	}
	for (char a = 'a'; a <= 'z'; a++)
		if (cnt[a])
		{
			s.push_back(a);
			cnt[a]--;
			rec(k + 1);
			cnt[a]++;
			s.pop_back();
		}
}
void solve()
{
	string x;
	cin >> x;
	n = x.size();
	for (auto i : x)
		cnt[i]++;
	rec(0);
	cout << out.size() << endl;
	sort(all(out));
	for (auto i : out)
		cout << i << endl;
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