#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

char sp(char a)
{
    if (a == 'L')
        return 'R';
    else return 'L';
}

void solve()
{

    int n, kids;
    cin >> n >> kids;
    string x;
    cin >> x;
    char next = 'L';
    for (int i = 0; i < n; i++)
    {
        if (next == x[i])
        {
            next = sp(next);
        } else
        {
            next = sp(x[i]);
            kids--;
        }
    }
    cout << max(0,kids) << endl;
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