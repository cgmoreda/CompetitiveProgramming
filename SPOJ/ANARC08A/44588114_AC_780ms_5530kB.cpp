#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
string x;


void flopr(int x1, int y1, int x2, int y2, string &state)
{
    int p1 = x1 * 3 + y1;
    int p2 = x1 * 3 + y2;
    int p3 = x2 * 3 + y2;
    int p4 = x2 * 3 + y1;
    int tmp = state[p1];
    state[p1] = state[p2];
    state[p2] = state[p3];
    state[p3] = state[p4];
    state[p4] = tmp;
}

void flopl(int x1, int y1, int x2, int y2, string &state)
{
    int p1 = x1 * 3 + y1;
    int p2 = x2 * 3 + y1;
    int p3 = x2 * 3 + y2;
    int p4 = x1 * 3 + y2;
    int tmp = state[p1];
    state[p1] = state[p2];
    state[p2] = state[p3];
    state[p3] = state[p4];
    state[p4] = tmp;
}

void flip(int pos, int d, string &state)
{
    if (pos == 1)
        (d == 1) ? flopr(0, 0, 1, 1, state) : flopl(0, 0, 1, 1, state);
    if (pos == 2)
        (d == 1) ? flopr(0, 1, 1, 2, state) : flopl(0, 1, 1, 2, state);
    if (pos == 3)
        (d == 1) ? flopr(1, 0, 2, 1, state) : flopl(1, 0, 2, 1, state);
    if (pos == 4)
        (d == 1) ? flopr(1, 1, 2, 2, state) : flopl(1, 1, 2, 2, state);
}

int getnum(string state)
{
    int a = 0;
    for (int i = 0; i < 9; i++)
        a *= 10, a += state[i] - '0';
    return a;
}


void solve()
{
    int y, y2;
    y = x[0] - '0';
    y2 = y / 2;


    queue<int> q;
    q.push(getnum(x.substr(1, 9)));
    map<int, int> vis, vis2;
    int level = 0;
    while (q.size())
    {
        int sz = q.size();
        while (sz--)
        {
            int stt = q.front();
            q.pop();
            if (vis.count(stt))
                continue;
            vis[stt] = level;
            string state = to_string(stt);
            for (int i = 1; i <= 4; i++)
            {
                flip(i, 1, state);
                int stn = getnum(state);
                if (!vis.count(stn))
                    q.push(stn);
                flip(i, 2, state);
            }
            for (int i = 1; i <= 4; i++)
            {
                flip(i, 2, state);
                int stn = getnum(state);
                if (!vis.count(stn))
                    q.push(stn);
                flip(i, 1, state);
            }
        }
        if (level == y2)
            break;
        level++;
    }
    while (q.size())
        q.pop();
    q.push({123456789});
    int ans = 100;
    level = 0;
    while (q.size())
    {
        int sz = q.size();
        while (sz--)
        {
            int stt = q.front();
            q.pop();

            if (vis.count(stt))
                ans = min(ans, level + vis[stt]);

            if (vis2.count(stt))
                continue;
            vis2[stt] = level;
            string state = to_string(stt);
            for (int i = 1; i <= 4; i++)
            {
                flip(i, 1, state);
                int stn = getnum(state);
                if (!vis2.count(stn))
                    q.push(stn);
                flip(i, 2, state);
            }
            for (int i = 1; i <= 4; i++)
            {
                flip(i, 2, state);
                int stn = getnum(state);
                if (!vis2.count(stn))
                    q.push(stn);
                flip(i, 1, state);
            }
        }
        if (level == y - y2)
            break;
        level++;
    }
    if (ans <= y)
        cout << ans << endl;
    else cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> x)
    {
        if (count(all(x), '0') == x.size())
            return 0;
        cout << t++ << ". ";
        solve();
    }

}