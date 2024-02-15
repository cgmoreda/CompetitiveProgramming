#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<ll>
#define vvi vector<vector<int>>
#define ii pair<int,int>

class DSU
{
private:
    vi p, rank, sz, nxt, cov;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        sz.assign(N + 1, 1);
        nxt.assign(N + 1, 0);
        cov.assign(N + 1, 0);
        for (int i = 0; i <= N; i++)
        {
            p[i] = i;
            nxt[i] = i + 1;
        }
    }

    DSU() = default;

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
            nxt[x] = nxt[y] = max(nxt[x], nxt[y]);
            cov[x] = cov[y] = max(cov[x], cov[y]);
            if (rank[x] > rank[y])
            {
                sz[x] = sz[y] = sz[x] + sz[y];
                p[y] = x;
            } else
            {
                sz[x] = sz[y] = sz[x] + sz[y];
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    void setcov(int i)
    {
        cov[findSet(i)] = 1;
    }

    int getnext(int i)
    {
        return nxt[findSet(i)];
    }

    int getcov(int i)
    {
        return cov[findSet(i)];
    }

    int getsize(int i)
    {
        return sz[findSet(i)];
    }


};

const int N = 1e7 + 10;

struct pos
{
    int l, r;
};

void solve()
{


    int n;
    cin >> n;
    vector <pos> poster(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> poster[i].l >> poster[i].r;
        mx = max(mx, poster[i].r);
    }
    DSU sup(mx + 1);
    reverse(all(poster));
    int cnt = 0;
    for (auto ps: poster)
    {
        while (sup.getcov(ps.l) != 0 && ps.l < ps.r)
        {
            ps.l = sup.getnext(ps.l);
        }
        if (sup.getcov(ps.l) == 0 && ps.l <= ps.r)
        {
            cnt++;
            sup.setcov(ps.l);
            for (int i = ps.l + 1; i <= ps.r;)
            {
                sup.join(i, i - 1);
                i = sup.getnext(i);
            }
            sup.setcov(ps.l);

        }

    }
    cout << cnt << endl;


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