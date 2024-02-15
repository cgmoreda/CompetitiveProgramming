#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>


class DSU
{
private:
    vi p, sz, sum;
    vector<multiset<int>> ms;
public:
    DSU(int N)
    {
        p.assign(N + 1, 0);
        ms = vector<multiset<int>>(N + 1);
        sz = vi(N + 1, 1);
        sum = vi(N + 1);
        for (int i = 0; i <= N; i++)
            p[i] = sum[i] = i, ms[i].insert(i);
    }


    bool isSameSet(int i, int j)
    {
        return p[i] == p[j];
    }

    void join(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = p[i], y = p[j];
            if (ms[x].size() < ms[y].size())
                swap(x, y);

            for (auto u: ms[y])
                ms[x].insert(u), sum[x] += u, sz[x]++, p[u] = x;
            ms[y].clear();
        }
    }

    void add(int u, int v)
    {
        ms[p[v]].insert(u);
        sz[p[v]]++;
        sum[p[v]] += u;
        p[u] = p[v];
    }

    void rem(int u)
    {

        ms[p[u]].erase(ms[p[u]].find(u));
        sum[p[u]] -= u;
        sz[p[u]]--;
    }

    int getsum(int i)
    {
        return sum[p[i]];
    }

    int getsz(int i)
    {
        return sz[p[i]];
    }

};

struct edge
{
    int u, v, w;

    bool operator==(edge a) const
    {
        return this->u == a.u && this->v == a.v && this->w == a.w;
    }

    bool operator<(edge a) const
    {
        return this->w < a.w;
    }
};

int n;
int m;

void solve()
{

    DSU ds(n);
    cin >> m;
    while (m--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int u, v;
            cin >> u >> v;
            ds.join(u, v);
        } else if (type == 2)
        {
            int u, v;
            cin >> u >> v;
            ds.rem(u);
            ds.add(u, v);
        } else if (type == 3)
        {
            int v;
            cin >> v;
            cout << ds.getsz(v) << " " << ds.getsum(v) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n)
    {
        solve();;
    }

}