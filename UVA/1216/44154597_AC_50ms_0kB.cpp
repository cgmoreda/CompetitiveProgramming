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

inline long long sq(long long x)
{
    return x * x;
}

struct point
{
    long long x, y;

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

void solve()
{
    int n;
    cin >> n;
    point a;
    vector<point> v;
    while (cin >> a.x && a.x != -1)
    {
        cin >> a.y;
        v.push_back(a);
    }
    DSU ds(v.size());
    vector<edge> oj;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            oj.push_back({i, j, v[i].dis(v[j])});
        }
    }
    sort(all(oj));
    int cnt = v.size();
    if (cnt == n)
    {
        cout << 0 << endl;
        return;
    }
    for (auto i: oj)
    {
        if (!ds.isSameSet(i.u,i.v))
        {
            ds.join(i.u, i.v);
            cnt--;
            if (cnt == n)
            {
                cout << (int)ceil(i.w) << endl;
                return;
            }
        }
    }
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
        solve();;
    }

}