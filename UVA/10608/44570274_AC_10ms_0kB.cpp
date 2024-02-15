#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

class DSU
{ // OOP style
private:
    vi p, rank, sz;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        sz.assign(N + 1, 1);
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
                sz[x] += sz[y];
                sz[y] = 0;
                p[y] = x;
            } else
            {
                sz[y] += sz[x];
                sz[x] = 0;
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int sizeSet(int x)
    {
        return sz[findSet(x)];
    }


};

int n, m;

void solve()
{
    cin >> n >> m;
    DSU ds(n + 1);
    int mx = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.unionSet(u, v);
        mx = max(mx, ds.sizeSet(u));
    }
    cout << mx << endl;

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