#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vin(v);
    vector<int> v2 = v;
    sort(v2.rbegin(), v2.rend());
    multiset<int> ms;
    for (int i = 0; i < k; i++)
    {
        ms.insert(v2[i]);
    }
    cout << v2[k / 2] << endl;
    for (auto i: v)
    {
        if (ms.find(i) != ms.end())
        {
            cout << i << " ";
            ms.erase(ms.find(i));
        }
    }
    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}