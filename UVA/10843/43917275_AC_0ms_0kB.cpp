#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define ii pair<int,int>
#define vvi vector<vector<ii>>


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

inline int sq(int x)
{
    return x * x;
}

struct point
{
    int x, y;

    double dis(point a) const
    {
        return sqrt(sq(x - a.x) + sq(y - a.y));
    }
};

struct edge
{
    int u, v;

    double w;

    bool operator==(edge a) const
    {
        return this->u == a.u && this->v == a.v && this->w == a.w;
    }

    bool operator<(edge a) const
    {
        return this->w < a.w;
    }
};


//don't forget to define mod
const ll mod = 2000000011;

long long power(long long x, long long k)
{
    long long ret = 1;
    while (k)
    {
        if (k & 1) ret = (ret * x) % mod;
        k >>= 1;
        x = (x * x) % mod;
    }
    return ret;
}


void solve()
{
    int n;
    cin >> n;

    if (n <= 2)
        cout << 1 << endl;
    else
        cout << power(n, n - 2) << endl;

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
        cout << "Case #" << ++z << ": ";
        solve();
    }

}