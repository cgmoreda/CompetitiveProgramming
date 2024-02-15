/*
    top to down aproach
    make a loop goes over the first rows and checks for the best routes
    of at every v[i][j] there is only one best route so dp on that
    gg bro

    approach 2
    itterative approach
    go down top from the row-1th row
    make the jth from the ith += the max of the botom 3 of it's
     make it one based to avoid any runtimes

 */

#include<iostream>

#include<cstring>

using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[200][200]={};
        for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];

        for (int i = n; i >= 0; i--) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] += max(arr[i + 1][j], max(arr[i + 1][j + 1], arr[i + 1][j - 1]));
            }
        }
        int mx = 0;
        for (int i = 0; i <= m; i++)mx = max(mx, arr[0][i]);
        cout << mx << endl;

    }
}



