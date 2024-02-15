#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>

void solve()
{

    int n;
    cin >> n;
    string x = to_string(n);
    int cnt = 0;
    for (auto i: x)
    {
        cnt += i - '0';
    }
    cout << (n % cnt == 0 ? "Yes\n" : "No\n") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}