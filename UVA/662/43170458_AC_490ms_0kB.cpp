#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vi vector<ll>
#define ll long long
int n, k;
// dp on [position][last depot][number of depots]
// number of depots? yeah cuz.
ll dp[220][220][220];
//  number greater than max possibly achived
ll oo = 1e14;
ll dist[220];

ll dope(int i = 0, int last_depot = 0, int cnt = 0) {

    ll &ret = dp[i][last_depot][cnt];
    if (~ret)return ret;

    if (i == 0) {
        // choose the first dpot
        ret = oo;
        ll sum_dis = 0;
        ret = min(ret, dope(1, 0, 1));
        for (; i < n; i++) {
            // calculating sum_dis for the one chosen
            sum_dis += (dist[i] - dist[i - 1]) * (i);
            // sum_dis = distance between jth and i (i:0->i-1)
            ret = min(ret, sum_dis + dope(i + 1, i, 1));
        }
        return ret;
    }
    if (i == n || cnt > k) {
        // restaurants finished
        if (cnt == k)// make sure choose exactly k
            return 0;
        return oo;
    }

    // skip -- no depot on this i
    ll c1 = dope(i + 1, last_depot, cnt) + (dist[i] - dist[last_depot]);

    // place depot at i
    ll sum_dis = 0;
    for (int j = last_depot; j < i; j++)
        if (dist[j] - dist[last_depot] > dist[i] - dist[j])
            sum_dis += (dist[i] - dist[j]) - ((dist[j] - dist[last_depot]));

    ll c2 = sum_dis + dope(i + 1, i, cnt + 1);
    return ret = min(c1, c2);
}

vi dpot;

void build(int i = 0, int last_depot = 0, int cnt = 0) {

    ll &ret = dp[i][last_depot][cnt];
    if (i == 0) {
        ll sum_dis = 0;
        if (ret == dope(1, 0, 1)) {
            dpot.push_back(0);
            build(1, 0, 1);
            return;
        }
        for (i = 1; i < n; i++) {

            sum_dis += (dist[i] - dist[i - 1]) * (i);
            if (ret == sum_dis + dope(i + 1, i, 1)) {
                dpot.push_back(i);
                build(i + 1, i, 1);
                return;
            }

        }
    }
    if (i == n || cnt > k) return;


    // skip -- no depot on this i
    ll c1 = dope(i + 1, last_depot, cnt) + (dist[i] - dist[last_depot]);
    ll sum_dis = 0;
    if (ret == c1) {
        build(i + 1, last_depot, cnt);
        return;
    }

    for (int j = last_depot; j < i; j++)
        if (dist[j] - dist[last_depot] > dist[i] - dist[j])
            sum_dis += (dist[i] - dist[j]) - ((dist[j] - dist[last_depot]));

    ll c2 = sum_dis + dope(i + 1, i, cnt + 1);

    if (ret == c2) {
        dpot.push_back(i);
        build(i + 1, i, cnt + 1);
    }

}


void solve() {

    memset(dp, -1, sizeof(dp));
    dpot.clear();

    for (int i = 0; i < n; i++)
        cin >> dist[i];

    // set dp and calculate ans
    ll fsum = dope();

    build();
    int nd = (int) dpot.size(), begin;

    //for(auto i:dpot)cout<<i<<" ";
    //cout<<endl;
    for (int j = 0, i = 0; i < dpot.size(); i++) {
        begin = j + 1;
        if (i == nd - 1)j = n;
        else
            while (j < n && (i == nd - 1 || abs(dist[dpot[i]] - dist[j]) < abs(dist[dpot[i + 1]] - dist[j]))) {
                j++;
            }

        cout << "Depot " << i + 1 << " at restaurant " << dpot[i]+1 << " serves restaurant";
        if (begin == j) {
            cout << " " << begin << endl;
        } else cout << "s " << begin << " to " << j << endl;

    }
    cout << "Total distance sum = " << fsum << endl;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z = 0;
    while (cin >> n >> k && n && k) {
        cout << "Chain " << ++z << endl;
        solve();
        cout << endl;
    }
}