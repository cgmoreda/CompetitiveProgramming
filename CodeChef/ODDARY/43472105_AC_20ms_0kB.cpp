#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>

/*
for (int i = 0; i < n; i++)
    {
        map<int, int> frq;
        for (int j = i; j < n; j++)
        {
            frq[v[j]]++;
            bool ok = true;
            for (auto f: frq)
            {
                if (f.second & 1)
                    ok = false;
            }
            if (ok)
                cout << i << " " << j << endl;
        }

    }
    */
void solve()
{
    int n = 2000;
    vector<int> v;
    int z = 2;
    v.push_back(1);
    while (v.size() < n)
    {
        v.push_back(z++);
        int t = v.size();
        for (int i = t - 2; i >= 0; i--)
            v.push_back(v[i]);

    }

    cin >> n;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 2000;
    vector<int> v;
    int z = 2;
    v.push_back(1);
    while (v.size() < n)
    {
        v.push_back(z++);
        int t = v.size();
        for (int i = t - 2; i >= 0; i--)
            v.push_back(v[i]);

    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;

    }

}