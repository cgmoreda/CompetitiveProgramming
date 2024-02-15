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
struct beeb
{
    int x, y;
};
int nb;
int n, m;
int dp[1 << 11][23];
vector<beeb> beebers;
int tmask;

int dis(int x, int y)
{
    beeb &a = beebers[x];
    beeb &b = beebers[y];
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int cntbit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n &= n - 1;
    }
    return cnt;
}

int dope(int mask, int pr)
{

    if (cntbit(mask) == nb)
    {
        return dis(pr, nb);
    }
    int &ret = dp[mask][pr];
    //if (~ret)return ret;
    ret = 1e9;
    for (int i = 0; i < nb; i++)
    {
        if (!(mask & (1 << i)))
        {
            tmask = mask | (1 << i);
            int ds = dis(i, pr);
            ret = min(ret, ds + dope(tmask, i));
        }
    }
    return ret;

}

void solve()
{
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    cin >> nb;
    beebers = vector<beeb>(nb + 1);
    beebers[nb].x = x - 1;
    beebers[nb].y = y - 1;
    for (int i = 0; i < nb; i++)
    {
        cin >> beebers[i].x >> beebers[i].y;
        beebers[i].x--;
        beebers[i].y--;
    }
    memset(dp, -1, sizeof(dp));
    cout<<"The shortest path has length ";
    cout << dope(0, nb) << endl;

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