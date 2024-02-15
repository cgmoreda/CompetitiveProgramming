#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

bool comp(pair<string, int> a, pair<string, int> b) {
    if (a.first.size() == b.first.size())
        return a < b;
    else return a.first.size() < b.first.size();
}

string x;

void solve() {
    vector<pair<string, int>> v;
    map<string, int> mp;
    bool ok = true;
    do {
        if (x == "()")break;
        int num = 0;
        int i;
        for (i = 1; x[i] != ','; i++) {
            num *= 10;
            num += x[i] - '0';
        }
        string tmp = x.substr(i + 1, x.size() - i - 2);
        v.emplace_back(tmp, num);
        mp[tmp]++;
        if (mp[tmp] == 2)ok = false;
    } while (cin >> x);

    sort(all(v), comp);
    for (auto i: v) {
        string tmp = i.first.substr(0, i.first.size() - 1);
        if (mp[tmp] == 0)ok = false;
    }
    int f=0;
    if (!ok) {
        cout << "not complete";
    } else for (auto i: v) {
        if(f++)cout<<" ";
        cout << i.second ;
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin>>x) {
        solve();;
    }

}