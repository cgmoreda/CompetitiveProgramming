#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

void solve()
{
    vector<string> in, out;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        in.push_back(x);
    }
    sort(in.rbegin(), in.rend());
    int n2 = n;
    for (int i = 0; i < n - 1; i++)
    {

        string x = in[i];
        string y = in[i + 1];
        string c;
        for (int j = 0; j < min(x.size(), y.size()); j++)
        {
            if (x[j] != y[j])
                break;
            c += x[j];
        }
        out.push_back(c);
    }
    sort(out.rbegin(), out.rend());
    if (out[n - k].size())
        cout << out[n - k] << endl;
    else
        cout << "EMPTY" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}