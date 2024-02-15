#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
vvi G;
vi col;
vi down;
string L, U;
int r;
vector<string> R;

string strajnfvojanv(int a) {
    string ret = "";
    for (int i = 0; i < 4; i++) {
        ret += char((a % 10)+'0');
        a /= 10;
    }
    reverse(all(ret));
    return ret;
}

int stoint(string x) {
    int num = 0;

    for (int i = 0; i < 4; i++) {
        num *= 10;
        num += x[i] - '0';
    }
    return num;
}

string add(string a, string b) {
    int x, y;
    x = stoint(a);
    y = stoint(b);
    return strajnfvojanv(x + y);
}

void bfs() {

    queue<string> q;
    map<string, int> vis;
    q.push(L);
    int cnt = 0;
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {
            string x = q.front();
            q.pop();
            if (x == U) {
                cout << cnt << "\n";
                return;
            }
            if (vis[x])continue;
            vis[x] = 1;

            for (int i = 0; i < r; i++)
                q.push(add(x, R[i]));
        }
        cnt++;
    }
    cout << "Permanently Locked\n";
}


void solve() {

    R = vector<string>(r);
    for (int i = 0; i < r; i++) {
        cin >> R[i];
    }
    bfs();
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> L >> U >> r && r) {
        cout<<"Case "<<t++<<": ";
        solve();
    }

}