#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>


int n, m;

void solve()
{
    vvi G;
    vi indegree;
    map<string, int> wid;
    map<int, string> wd;
    int id;
    id = 0;
    G = vvi(n + 1);
    indegree = vi(n + 1);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string x, y;
        getline(cin, x);
        stringstream line(x);
        line >> x;
        if (!wid.count(x))
        {
            wid[x] = id;
            wd[id] = x;
            id++;
        }
        while (line >> y)
        {
            if (!wid.count(y))
            {
                wid[y] = id;
                wd[id] = y;
                id++;
            }
            G[wid[x]].push_back(wid[y]);
            indegree[wid[y]]++;
        }
    }
    set<int> s;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        s.insert(i);
        if (indegree[i] == 0)
            ms.insert(i);
    }
    while (ms.size())
    {
        int node = *ms.begin();
        ms.erase(ms.begin());
        s.erase(node);
        for (auto i: G[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                ms.insert(i);
        }
    }
    vector<string> out;
    for (auto i: s)
        out.push_back(wd[i]);
    sort(all(out));
    cout << out.size() << endl;
    int z = 0;
    for (auto i: out)
    {
        if (z++)
            cout << " ";;
        cout << i;
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
    while (cin >> n && n)
    {
        solve();
    }

}
