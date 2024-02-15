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

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    vi vis(10010);
    while (!q.empty()) {
        int cp = q.front().first, cd = q.front().second;
        q.pop();
        if (vis[cp])
            continue;
        if (cp == b)return cd;
        vis[cp] = 1;
        for (auto u: G[cp]) {
            q.push({u, cd + 1});
        }
    }
    return -1;
}

void solve() {

    int a, b;
    cin >> a >> b;

    int ans = bfs(a, b);
    if (ans == -1)cout << "Impossible\n";
    else cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1000; i <= 9999; i++)
        if (prime(i))
            primes.push_back(i);

    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size(); j++) {
            if (diff(primes[i], primes[j]) == 1) {
                G[primes[i]].push_back(primes[j]);
                G[primes[j]].push_back(primes[i]);
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}