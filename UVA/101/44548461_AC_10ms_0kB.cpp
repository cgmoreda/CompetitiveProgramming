#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
vector<deque<int>> v;
vector<int> p;

void solve()
{
    int n;
    cin >> n;
    v = vector<deque<int>>(n);
    p = vector<int>(n);
    for (int i = 0; i < n; i++)
        v[i].push_back(i), p[i] = i;
    while (true)
    {
        int a, b;
        string x;
        cin >> x;
        if (x == "quit")
            break;
        else if (x == "move")
        {
            cin >> a >> x >> b;
            if (p[a] == p[b])
                continue;

            if (x == "onto")
            {
                while (v[p[a]].back() != a)
                {
                    int u = v[p[a]].back();
                    v[p[a]].pop_back();
                    v[u].push_front(u);
                    p[u] = u;
                }
                v[p[a]].pop_back();
                while (v[p[b]].back() != b)
                {
                    int u = v[p[b]].back();
                    v[p[b]].pop_back();
                    v[u].push_front(u);
                    p[u] = u;
                }
                p[a] = p[b];
                v[p[b]].push_back(a);
            } else
            {
                while (v[p[a]].back() != a)
                {
                    int u = v[p[a]].back();
                    v[p[a]].pop_back();
                    v[u].push_front(u);
                    p[u] = u;
                }
                v[p[a]].pop_back();
                p[a] = p[b];
                v[p[b]].push_back(a);
            }
            p[a] = p[b];
        } else if (x == "pile")
        {
            cin >> a >> x >> b;
            if (p[a] == p[b])
                continue;

            if (x == "onto")
            {
                while (v[p[b]].back() != b)
                {
                    int u = v[p[b]].back();
                    v[p[b]].pop_back();
                    v[u].push_front(u);
                    p[u] = u;
                }
            }
            vector<int> tmp;
            bool found = false;
            for (auto i: v[p[a]])
            {
                if (i == a)
                    found = true;
                if (found)
                    tmp.push_back(i);
            }
            while (v[p[a]].back() != a)
                v[p[a]].pop_back();
            v[p[a]].pop_back();
            for (auto i: tmp)
            {
                p[i] = p[b];
                v[p[b]].push_back(i);
            }
            v[a].clear();
        }

    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (auto j: v[i])
            cout << " " << j;
        cout << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();;
    }

}