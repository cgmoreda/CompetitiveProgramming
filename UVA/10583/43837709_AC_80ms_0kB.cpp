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
    vi p, rank;
public:
    UnionFind(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
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
                p[y] = x;
            } else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int n, m;

void solve()
{
    UnionFind dsu(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.unionSet(x, y);
    }
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(dsu.findSet(i + 1));
    cout << s.size() << endl;
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
        cout << "Case " << t++ << ": ";
        solve();
    }

}