#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<char>>
#define ii pair<int,int>
#define ll long long

void print(int l, int w, int x, int y)
{
    char a = 'A';
    vvi out(l, vector<char>(w));
    for (int i = 0; i < l; i += x)
    {
        for (int j = 0; j < w; j += y)
        {
            for (int g = i; g < i + x; g++)
            {
                for (int k = j; k < j + y; k++)
                {

                    out[g][k] = a;
                }
            }
            a = char(a + 1);
        }
    }
    for (auto i: out)
    {
        for (auto j: i)
        {
            cout << j;
        }
        cout << endl;
    }
}

void solve()
{

    int l, w, a, n;
    cin >> l >> w >> n;
    vector<int> div;
    if ((l * w) % n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    a = l * w / n;

    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
            div.push_back(i);
    }
    vector<pair<int, int>> pb;
    for (int i = 0; i < div.size(); i++)
    {
        pb.push_back({div[i], a / div[i]});
    }
    for (int i = 0; i < div.size(); i++)
    {
        int x = pb[i].first;
        int y = pb[i].second;
        if (l % x == 0 && w % y == 0)
        {
            print(l, w, x, y);
            return;
        }
    }
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