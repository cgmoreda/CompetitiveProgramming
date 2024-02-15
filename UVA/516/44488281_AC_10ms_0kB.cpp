#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int n, m;


//don't forget to define mod
long long power(long long x, long long k)
{
    long long ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x);
        k >>= 1;
        x = (x * x);
    }
    return ret;
}

string x;

void solve()
{
    stringstream in(x);
    int base, prr;
    ll num = 1;
    while (in >> base)
    {
        in >> prr;
        num *= power(base, prr);
    }
    num -= 1;
    map<int, int> mp;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            mp[-i]++;
            num /= i;
        }
    }
    if (num != 1)
        mp[-num]++;

    int z = 0;
    for (auto i: mp)
    {
        if (z++)
            cout << " ";
        cout << -i.first << " " << i.second;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (getline(cin, x) && x != "0")
    {
        solve();
    }

}