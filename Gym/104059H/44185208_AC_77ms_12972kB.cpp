#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
const int N = 1e4 + 10;
vector<set<char>> freq;
int n, m;

void dope(vector<set<char>> &pr)
{
    bool ok = false;
    set<char> dont;
    for (auto i: pr)
    {
        ok |= i.size() > 1;
        if (ok)
            break;
    }
    if (!ok)
        return;
    vector<set<char>> nw;
    for (auto i: pr)
    {
        if (i.size() == 1)
        {
            nw.push_back(i);
            nw.push_back(i);
            dont.insert(*i.begin());
        } else
        {
            set<char> s1, s2;
            int x = 0;
            for (auto j: i)
            {
                if (x < i.size() / 2)
                    s1.insert(j);
                else
                    s2.insert(j);
                x++;
            }
            nw.push_back(s1);
            nw.push_back(s2);
        }
    }
    set<char> out, in;
    int z = 0;
    for (auto i: nw)
    {
        if (z % 2)
        {
            for (auto j: i)
                out.insert(j);
        } else
        {
            for (auto j: i)
                in.insert(j);
        }
        z++;
    }
    string x;
    for (auto i: in)
    {
        if (dont.find(i) == dont.end())
            x += i;
    }
    cout << "? " << x << endl;
    int num;
    cin >> num;
    vector<int> pos(n + 1);
    while (num--)
    {
        int pp;
        cin >> pp;
        pos[pp] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (freq[i].size() == 1)
            continue;
        if (pos[i] == 1)
        {
            for (auto j: out)
            {
                //if (dont.find(j) != dont.end())
                freq[i].erase(j);
            }
        } else
        {
            for (auto j: in)
            {
                // if (dont.find(j) != dont.end())
                freq[i].erase(j);
            }
        }
    }
    dope(nw);
}

void solve()
{
    set<char> t;
    cout << "? ";
    for (char c = 'a'; c <= 'z'; c++)
    {
        t.insert(c);
        cout << c;
    }
    cout << endl;

    cin >> n;

    freq = vector<set<char>>(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        freq[i] = t;
    }
    vector<set<char>> nw = {t};
    dope(nw);
    cout << "! ";
    for (auto i: freq)
    {
        if (i.size() == 1)
            cout << *i.begin();
    }
    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

}