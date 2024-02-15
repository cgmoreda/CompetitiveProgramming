#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

class UnionFind
{ // OOP style
private:
    vi p, rank, s;
public:
    UnionFind(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        s.assign(N + 1, 1);
        for (int i = 0; i <= N; i++)
            p[i] = i;
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                s[x] += s[y];
                p[y] = x;
            } else
            {
                s[y] += s[x];
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int getsize(int x)
    {
        return s[findSet(x)];
    }
};

int n, m;

void solve()
{
    int id = 0;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        if (!mp.count(x))
            mp[x] = id++;
    }
    UnionFind dsu(n);
    for (int i = 0; i < m; i++)
    {
        string x, y;
        cin >> x >> y;
        dsu.unionSet(mp[x], mp[y]);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dsu.getsize(i));
    cout << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1;
    //cin >> t;
    while (cin >> n >> m && n)
    {
        solve();
    }

}