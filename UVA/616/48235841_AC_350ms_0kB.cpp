#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define ll long long


ll n;

ll solve(int solvefornum, int current = 0, ll sum = 0) {

    if (current == 0) {
        if (sum % solvefornum == 0)
            return solvefornum;
        else return -1;
    } else {
        if (sum % solvefornum == 0) {
            return -1;
        } else {
            sum--;
            if (sum % solvefornum == 0) {
                return solve(solvefornum, current - 1, sum - (sum / solvefornum));
            } else return -1;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;

    //cin >> t;
    while (cin >> n) {
        if (n < 0)break;
        set<ll> divs;
        ll k = n - 1;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                divs.insert(i);
                divs.insert(k / i);
            }
        }
        ll ans = -1;
        for (auto i: divs) {
            if(i==1)continue;
            ans = max(ans, solve(i, i-1, k - (k / i)));
        }
        if (ans == -1) {
            cout << n << " coconuts, " << "no solution" << endl;
        } else
            cout << n << " coconuts, " << ans << " people and 1 monkey" << endl;
    }


}