#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda  

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

double d, l, b, p, down, up, v;
const double pi = 3.14159265359;

double solve()
{
    double totaltime = 0;
    d /= 12;// inch to feet
    d /= 2;// dia to radius
    while (v > 1e-6)
    {
        totaltime += up + down + l / p + sqrt((2 * l) / 386.4);
        l += (b / (d * d * pi)) * 12;
        v -= b;
    }
    return totaltime;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> up && up >= 1.0)
    {
        if (t != 1) printf("\n");
        cin >> d >> l >> b >> p >> down >> v;
        printf("Scenario %d:\n", t);
        printf("     up hill%19.2lf sec\n", up);
        printf("     well diameter%13.2lf in\n", d);
        printf("     water level%15.2lf in\n", l);
        printf("     bucket volume%13.2lf cu ft\n", b);
        printf("     bucket ascent rate%8.2lf in/sec\n", p);
        printf("     down hill%17.2lf sec\n", down);
        printf("     required volume%11.2lf cu ft\n", v);
        printf("     TIME REQUIRED%13.2lf sec\n", solve());
        t++;
    }

}