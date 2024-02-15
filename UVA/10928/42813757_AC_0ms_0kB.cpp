#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()

int dope() {

}

void solve() {

    int n;
    cin >> n;
    vector<int> v(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);
        int space = 1;
        for (char xi : x) {
            if (xi == ' ')
                space = 1;
            else if (space)
                v[i]++, space = 0;
        }
    }

    int mn = *min_element(all(v));
    int fst=0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == mn) {
            if(fst){
                cout<<" ";
            }
            else fst=true;
            cout << i + 1;
        }
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();;
    }

}