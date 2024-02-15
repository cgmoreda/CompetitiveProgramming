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
int n;
vvi G;
vvi maka;
int dp[1 << 17][17];
int vis[1 << 17][17];
int id;

int dope(int mask, int i)
{
    if (i == n)
        return 0;

    if (vis[mask][i] == id)return dp[mask][i];
    vis[mask][i] = id;

    int &ret = dp[mask][i];
    ret = dope(mask, i + 1);

    for (auto mak: maka[i])
    {
        if (!(mask & mak))
            ret = max(ret, 1 + dope((mask | mak), i + 1));
    }
    return ret;
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();
// code
    id++;
    G = vvi(n + 1);
    maka = vvi(n + 1);
    for (int u = 0, v, m; u < n; u++)
    {
        cin >> m;
        while (m--)
        {
            cin >> v;
            G[u].push_back(v);
        }
    }
    vvi &maka2 = maka;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int mnmask{};

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                mnmask |= (1 << i);
                for (auto v: G[i])
                {
                    mnmask |= (1 << v);
                }
            }
        }

        if (mnmask == (1 << n) - 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    if (maka[i].empty() || (!maka[i].empty() && (maka[i][0] & mask) != maka[i][0]))
                        maka[i].push_back(mask);
                    break;
                }
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "Time taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;
    cout << dope(0, 0) << endl;

    auto stop2 = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(stop2 - stop);
    cerr << "Time2 taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1, z = 1;
    //cin >> t;
    while (cin >> n && n)
    {
        cout << "Case " << z++ << ": ";
        solve();
    }

}