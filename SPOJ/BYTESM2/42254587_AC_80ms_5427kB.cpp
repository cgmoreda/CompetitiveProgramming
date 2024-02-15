#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, a[200][200] = {}, mx = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> a[i][j];

        for (int i = n; i >= 0; i--)
            for (int j = 1; j <= m; j++)
                a[i][j] += max(a[i + 1][j], max(a[i + 1][j + 1], a[i + 1][j - 1]));
        for (int i = 0; i <= m; i++)mx = max(mx, a[0][i]);
        cout << mx << endl;

    }
}