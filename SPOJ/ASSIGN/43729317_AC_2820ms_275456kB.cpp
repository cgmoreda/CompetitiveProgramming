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

vvi r(22, vi(22));
int n;
ll dp[1 << 22][22];
int vis[1 << 22][22];
int id;

ll dope(int topics_taken, int student)
{

    if (student == n)
    {
        return 1;
    }
    if (vis[topics_taken][student] == id)return dp[topics_taken][student];
    vis[topics_taken][student] = id;
    ll &ret = dp[topics_taken][student] = 0;
    for (int top = 0; top < n; top++)
    {
        if (!(topics_taken & (1 << top)) && r[student][top])
        {
            ret += dope((topics_taken | (1 << top)), student + 1);
        }
    }
    return ret;

}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> r[i][j];
        }
    }
    id++;
    cout << dope(0, 0) << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    auto start = chrono::high_resolution_clock::now();
    while (t--)
    {
        solve();
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "Time taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;
}