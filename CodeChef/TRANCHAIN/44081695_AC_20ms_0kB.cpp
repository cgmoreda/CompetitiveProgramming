#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

void solve()
{

    int a{}, b{}, ab{}, o{};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (x == "A")
            a++;
        else if (x == "B")
            b++;
        else if (x == "AB")
            ab++;
        else if (x == "O")
            o++;
    }
    cout << o + ab + max(a, b) << endl;

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