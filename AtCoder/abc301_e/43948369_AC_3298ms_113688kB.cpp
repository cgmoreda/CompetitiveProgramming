#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll int
#define ii pair<ll,ll>

int n, m;
char a[333][333];
ll d[22][22];
struct point
{
    int x, y;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll dfsvis[333][333];
ll id;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int ex, ey;

int bfs(int i, int j)
{

    queue<ii > q;
    int level = 0;
    q.push({i, j});
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (dfsvis[i][j] == id)
                continue;
            dfsvis[i][j] = id;
            if (i == ex && j == ey)
                return level;
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (valid(x, y) && dfsvis[x][y] != id && a[x][y] != '#')
                    q.push({x, y});
            }
        }
        level++;
    }
    return 1e8;
}


struct comp
{

    bool operator()(pair<int, ii > a, pair<int, ii > b)
    {
        return (a.first > b.first);

    }
};

bool vis2[1 << 22][22];

void solve()
{

    ll t;
    deque<point> cand;
    cin >> n >> m >> t;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                cand.push_front({i, j});
            } else if (a[i][j] == 'G')
            {
                ex = i, ey = j;
            } else if (a[i][j] == 'o')
            {
                cand.push_back({i, j});
            }
        }
    }
    cand.push_back({ex, ey});

    int c = (int) cand.size();

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ++id;
            ex = cand[j].x;
            ey = cand[j].y;
            d[i][j] = bfs(cand[i].x, cand[i].y);
        }
    }
    priority_queue<pair<ll, ii >, vector<pair<ll, ii>>, comp> pq;
    pq.push({0, {1, 0}});
    int mx = -1;
    int op = c - 2;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cerr << d[i][j] << " ";
        }
        cerr << endl;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "Time taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;

    while (!pq.empty())
    {
        int moves = pq.top().first;
        int mask = pq.top().second.first;
        int last = pq.top().second.second;
        pq.pop();

        if (vis2[mask][last]) continue;
        vis2[mask][last] = true;

        if (moves + d[last][c - 1] <= t)
            mx = max(mx, __builtin_popcount(mask) - 1);
        else continue;
        if (mx == op)
            break;
        for (int nxt = 1; nxt < c - 1; nxt++)
        {
            int nmask = mask | (1 << nxt);
            if (mask != nmask && !vis2[nmask][nxt] && moves + d[last][nxt] + d[nxt][c - 1] <= t)
                pq.push({moves + d[last][nxt], {nmask, nxt}});
        }

    }

    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "Time taken :" << ((long double) duration.count()) / ((long double) 1e9) << " s" << endl;
    cout << mx << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();


}