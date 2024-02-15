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

struct rd
{
    int u, v, c;


};

bool comp(rd a, rd b)
{
    
    return a.c < b.c;
}

void solve()
{
    vector<rd> edges;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            char y;
            if (j)
                cin >> y;
            cin >> x;
            if (j <= i)continue;
            if (x)
            {
                rd r{};
                r.u = i;
                r.v = j;
                r.c = x;
                edges.emplace_back(r);
            }
        }
    }
    m = edges.size();
    sort(all(edges), comp);
    DSU ds(n + 1);
    vector<string> ans;
    for (int i = 0; i < m; i++)
    {
        rd e = edges[i];
        if (!ds.isSameSet(e.u, e.v))
        {
            ds.unionSet(e.u, e.v);
            string tmp;
            tmp += char('A' + e.u);
            tmp += '-';
            tmp += char('A' + e.v);
            tmp += ' ';
            tmp += to_string(e.c);
            tmp += '\n';
            ans.emplace_back(tmp);
        }
    }
    for (auto i: ans)cout << i;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1, z = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++z << ":\n";
        solve();
    }

}