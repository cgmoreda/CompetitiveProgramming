#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define sqr(v) ((v)*(v))

struct box {
    double left, right, top, bottom;
};

double dis(box a, box b) {

  
    double disx, disy;
    if (a.bottom > b.bottom)swap(a, b);
    // a starts later
    if (b.top == a.top || a.bottom == b.bottom)
        disy = 0.0;
    else
        disy = max(0.0, b.bottom - a.top);
    if (a.left > b.left)swap(a, b);
    if (b.left == a.left || a.right == b.right)
        disx = 0.0;
    else
        disx = max(0.0, b.left - a.right);
    return sqrt(sqr(disx) + sqr(disy));
}

void solve() {

    int n, h, w;
    cin >> n >> h >> w;
    vector<box> v(n + 3);
    box b{0, 0, 0, 0};
    b.right = w, b.bottom = -1;
    v[0] = (b);
    for (int i = 1; i <= n; i++) {
        int hight, width, up, side;
        cin >> hight >> width >> up >> side;
        v[i].bottom = up;
        v[i].top = v[i].bottom + hight;
        v[i].right = (side == 1 ? w : width);
        v[i].left = (side == 0 ? 0 : w - width);
    }
    b.bottom = b.top = h;
    v[n + 1] = (b);
    vector<vector<double>> adj(n + 3, vector<double>(n + 3, -1));

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            adj[i][j] = dis(v[i], v[j]);
        }
    }

    for (int k = 0; k <= n + 1; k++) {
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << adj[0][n + 1] << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("street.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}