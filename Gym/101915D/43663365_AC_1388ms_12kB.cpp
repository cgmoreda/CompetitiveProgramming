#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<set<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>


int countbit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n &= n - 1;
    }
    return cnt;
}

void solve()
{

    int p;
    cin >> p;
    int n;
    cin >> n;
    vi G(p + 1);
    for (int i = 0; i < n; i++)
    {
        int b, g;
        cin >> b >> g;
        b--;
        g--;
        G[g] |= (1 << b);
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << (p)) ; mask++)
    {
        int g = countbit(mask);
        int b = 0;
        bool f = true;
        for (int i = 0; i < p; i++)
        {

            if (mask & (1 << i))
            {
                if (f)
                    b = G[i],
                            f = false;
                else
                    b &= G[i];
            }
        }

        ans = max(ans, g + countbit(b));
    }
    cout << ans << endl;

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