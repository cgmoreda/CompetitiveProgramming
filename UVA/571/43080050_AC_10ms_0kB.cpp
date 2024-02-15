#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vi primes;
vvi G(10001);


bool prime(long long x) {
    if (x < 2)return false;
    if (x % 2 == 0)return x == 2;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0)return false;
    }
    return true;
}

int diff(int a, int b) {
    int cnt = 0;
    while (a > 0 && b > 0) {
        cnt += (a % 10 != b % 10);
        a /= 10, b /= 10;
    }
    return cnt;
}

string ans;

void poor(int &cf, int &ct, int mxsz) {

    int tmp = min(ct + cf, mxsz);
    cf = max(0, cf - (mxsz - ct));
    ct = tmp;

}

void bfs(int a, int b, int c) {
    queue<tuple<int, int, string>> q;
    q.push({0, 0, ""});
    vvi vis(a + 1, vi(b + 1, 0));
    while (!q.empty()) {
        int ca = get<0>(q.front()), cb = get<1>(q.front());
        string ops = get<2>(q.front());
        q.pop();
        if (vis[ca][cb] == 1)
            continue;
        if (ca == c || cb == c) {
            ans = ops + '0';
            return;
        }
        vis[ca][cb] = 1;

        if (ca != 0) {
            ops.push_back('1');
            q.push({0, cb, ops});
            ops.pop_back();
        }
        if (cb != 0) {
            ops.push_back('2');
            q.push({ca, 0, ops});
            ops.pop_back();
        }
        if (ca != a) {
            ops.push_back('3');
            q.push({a, cb, ops});
            ops.pop_back();
        }

        if (cb != b) {
            ops.push_back('4');
            q.push({ca, b, ops});
            ops.pop_back();
        }
        // 5 poor b a
        if (cb && ca != a) {
            ops.push_back('5');
            int ta = ca, tb = cb;
            poor(tb, ta, a);
            q.push({ta, tb, ops});
            ops.pop_back();
        }
        // 6 poor a b
        if (ca && cb != b) {
            ops.push_back('6');
            poor(ca, cb, b);
            q.push({ca, cb, ops});
            ops.pop_back();
        }
    }
}

int a, b, c;

void solve() {

    bfs(a, b, c);
    //cout << ans << endl;
    for (auto i: ans) {
        switch (i) {
            case '0':
                cout << "success";
                break;
            case '1':
                cout << "empty A";
                break;
            case '2':
                cout << "empty B";
                break;
            case '3':
                cout << "fill A";
                break;
            case '4':
                cout << "fill B";
                break;
            case '5':
                cout << "pour B A";
                break;
            case '6':
                cout << "pour A B";
                break;
        }
        cout << endl;
    }

}

/*
 0 sucess
 1 empty a
 2 empty b
 3 fill a
 4 fill b
 5 poor b a
 6 poor a b
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> a >> b >> c) {
        solve();;
    }

}