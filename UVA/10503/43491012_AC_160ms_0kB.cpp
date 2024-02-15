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
#define sq(x) ((x)*(x))
struct dom
{
    int l, r;
};


int n, m;
vector<dom> peices;
double dp[1 << 16][16][8][8];
bool ok;

void dope(int mask, int l, int r, int cnt = n)
{
    if (cnt == 0)
    {
        ok |= (l == r);
        return;
    }
    vector<dom> &peices1 = peices;

    if (dp[mask][cnt][l][r])return;
    dp[mask][cnt][l][r] = 1;
    for (int i = 0; i < m; i++)
    {
        if (!(mask & (1 << i)))
        {
            if (peices[i].l == l)
                dope(mask | (1 << i), peices[i].r, r, cnt - 1);
            if (peices[i].l == r)
                dope(mask | (1 << i), l, peices[i].r, cnt - 1);
            if (peices[i].r == l)
                dope(mask | (1 << i), peices[i].l, r, cnt - 1);
            if (peices[i].r == r)
                dope(mask | (1 << i), l, peices[i].l, cnt - 1);
        }
    }
}


void solve()
{
    peices.clear();
    cin >> m;
    int l1, l2, r1, r2;
    cin >> l1 >> l2 >> r1 >> r2;
    for (int i = 0; i < m; i++)
    {
        dom a{};
        cin >> a.l >> a.r;
        peices.push_back(a);
    }
    ok = false;

    dope(0, l2, r1, n);

    if (ok)
        cout << "YES\n";
    else cout << "NO\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n && n)
    {
        // cout << "Case " << t++ << ": ";
        solve();
    }

}