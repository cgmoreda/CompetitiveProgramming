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
    vi p, rank, toleft, toright, dis;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        toright.assign(N + 1, 0);
        toleft.assign(N + 1, 0);
        dis.assign(N + 1, 0);
        for (int i = 0; i <= N; i++)
        {
            p[i] = i;
            toleft[i] = i - 1;
            toright[i] = i + 1;
        }

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
            dis[x] = dis[y] = dis[x] + dis[y];
            toright[x] = toright[y] = max(toright[x], toright[y]);
            toleft[x] = toleft[y] = min(toleft[x], toleft[y]);
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

    int getleft(int i)
    {
        return toleft[findSet(i)];
    }


    int getright(int i)
    {
        return toright[findSet(i)];
    }

    void setdis(int i, int d)
    {
        dis[i] = d;
    }

    int getdis(int i)
    {
        return dis[findSet(i)];
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

int dp[1001][60][60];
int vis[1001][60][60];
int id;

int dope(vector<int> &dis, int L, int l = 0, int r = -1)
{
    if (r == -1)
        r = dis.size() - 1;
    if (r - l < 1)
        return 0;

    int newL = dis[l];

    int &ret = dp[L][l][r];
    if (vis[L][l][r] == id)
        return ret;
    vis[L][l][r] = id;
    ret = 1e9;
    for (int i = l + 1; i <= r; i++)
    {

        ret = min(ret, L + dope(dis, newL, l, i - 1) + dope(dis, L - newL, i, r));
        newL += dis[i];
    }
    return ret;

}

ll n, m, l;


void solve()
{
    id++;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    v.push_back(l);
    vector<int> dis;
    for (int i = 0; i <= n; i++)
    {
        dis.push_back(v[i + 1] - v[i]);
    }
    cout << "The minimum cutting is ";
    cout << dope(dis, l) << "." << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1, z = 0;
    //cin >> t;
    while (cin >> l && l)
    {
        cin >> n;
        solve();
    }

}


