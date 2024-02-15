#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

set<string> pos;

bool win(string x, char c) {
    for (int i = 0; i < 3; i++)
        if ((x[i * 3 + 0] == c && x[i * 3 + 1] == c && x[i * 3 + 2] == c) ||
            (x[0 * 3 + i] == c && x[1 * 3 + i] == c && x[2 * 3 + i] == c))
            return true;
    if ((x[0 * 3 + 0] == c && x[1 * 3 + 1] == c && x[2 * 3 + 2] == c) ||
        (x[1 * 3 + 1] == c && x[0 * 3 + 2] == c && x[2 * 3 + 0] == c))
        return true;
    return false;
}


void dope(int i = 0, string x = ".........", int nx = 0, int no = 0) {
    if (i==9||(nx + no >= 5 && (win(x, 'X')  || win(x, 'O'))) ) {
        pos.insert(x);  
        return;
    }
    pos.insert(x);
    char mv;
    if (nx == no)mv = 'X', nx++;
    else mv = 'O', no++;

    for (int j = 0; j < 9; j++)
        if (x[j] == '.') {
            x[j] = mv;
            dope(i + 1, x, nx, no);
            x[j] = '.';
        }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dope();
    int t = 1;
    cin >> t;
    while (t--) {
        string a, b, c, x;
        cin >> a >> b >> c;
        x.append(a);
        x.append(b);
        x.append(c);
        if (pos.find(x) != pos.end())
            cout << "yes\n";
        else cout << "no\n";;
    }

}