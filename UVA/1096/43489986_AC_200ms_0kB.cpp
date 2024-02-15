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
struct point
{
    double x, y;
};
int n, m, b1, b2;
string x, y;
double dp[101][101][101][2][2];
vector<point> cc;

double dis(point a, point b)
{
    return sqrt(sq((b.x - a.x)) + sq((b.y - a.y)));
}

double dope(int k = 1, int i = 0, int j = 0, int f1 = 0, int f2 = 0)
{
    if (k == n - 1)
    {
        if (f1 && f2)
            return dis(cc[k], cc[j]) + dis(cc[k], cc[i]);
        else return 1e9;
    }

    double &ret = dp[k][i][j][f1][f2];
    if (ret > 0)return ret;

    bool sp = ((k == b1) || (k == b2));


    double c1 = dis(cc[k], cc[i]) + dope(k + 1, k, j, f1 | sp, f2);
    double c2 = dis(cc[k], cc[j]) + dope(k + 1, i, k, f1, sp | f2);

    return ret = min(c1, c2);
}

vi out;

bool equals(double a, double b)
{
    return abs(a - b) < 1e-7;
}

void build(int k = 1, int i = 0, int j = 0, int f1 = 0, int f2 = 0)
{
    if (k == n - 1)
    {
        cout << k << " ";
        reverse(all(out));
        for (auto f: out)
            cout << f << " ";
        return;
    }

    double ret = dp[k][i][j][f1][f2];
    bool sp = ((k == b1) || (k == b2));


    double c1 = dis(cc[k], cc[i]) + dope(k + 1, k, j, f1 | sp, f2);
    double c2 = dis(cc[k], cc[j]) + dope(k + 1, i, k, f1, sp | f2);


    if (equals(c1, ret))
    {
        cout << k << " ";
        build(k + 1, k, j, f1 | sp, f2);
    } else if (equals(c2, ret))
    {
        out.push_back(k);
        build(k + 1, i, k, f1, sp | f2);
    }
}

void solve()
{
    cc.clear();
    out.clear();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        point a;
        cin >> a.x >> a.y;
        cc.push_back(a);
    }
    cout << fixed << setprecision(2) << dope() << endl;
    cout << 0 << " ";
    build();
    cout << 0 << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> b1 >> b2 && n && b1 && b2)
    {
        cout<<"Case "<<t++<<": ";
        solve();
    }

}