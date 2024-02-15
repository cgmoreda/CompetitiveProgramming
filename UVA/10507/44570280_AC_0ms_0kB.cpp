#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

class DSU
{
private:
    vi p, rank;
public:
    DSU(int N)
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

    void join(int i, int j)
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

struct edge
{
    int u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

ll n, m;

void solve()
{

    char a, b, c;
    cin >> a >> b >> c;
    map<char, int> awake;
    awake[a] = 1;
    awake[b] = 1;
    awake[c] = 1;
    vvi G(140);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int f = n - 3;
    int years = 0;
    for (int i = 0; i < n; i++)
    {
        if (!f)
            break;
        years++;
        set<int> woke;
        for (int j = 'A'; j <= 'Z'; j++)
        {
            if (awake[j] || G[j].empty())continue;
            int cnt = 0;
            for (auto k: G[j])
            {
                cnt += awake[k];
            }
            if (cnt >= 3)
                woke.insert(j);
        }
        for (auto i: woke)
        {
            f--;
            awake[i] = 1;
        }
    }

    if (f)
    {
        cout << "THIS BRAIN NEVER WAKES UP" << endl;
    } else cout << "WAKE UP IN, " << years << ", YEARS" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, z = 0;
    //cin >> t;
    while (cin >> n >> m && n)
    {
        solve();
    }

}