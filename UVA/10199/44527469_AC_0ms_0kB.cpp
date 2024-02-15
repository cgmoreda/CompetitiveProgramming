#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda  

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
int n;
vvi G;
vi dnum, dlow, pr;
int id;
int dfsroot, cntroot;
set<int> arc;

void tarjan(int node)
{
    if (dnum[node] != -1)
        return;
    dnum[node] = dlow[node] = ++id;

    for (auto u: G[node])
    {
        if (dnum[u] == -1)
        {
            pr[u] = node;
            tarjan(u);
            if (dnum[node] <= dlow[u])
                if (node == dfsroot)cntroot++;
                else arc.insert(node);

            dlow[node] = min(dlow[node], dlow[u]);

        } else if (u != pr[node])
        {
            dlow[node] = min(dlow[node], dnum[u]);
        }
    }

}

void solve()
{
    dlow = pr = vi(n + 1);
    dnum = vi(n + 1, -1);
    id = 0;
    int cid = 0;
    arc.clear();
    map<string, int> cmp;
    map<int, string> out;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        cmp[x] = cid;
        out[cid] = x;
        cid++;
    }
    int m;
    cin >> m;
    G = vvi(n + 1);
    for (int i = 0; i < m; i++)
    {
        string x, y;
        cin >> x >> y;
        G[cmp[x]].push_back(cmp[y]);
        G[cmp[y]].push_back(cmp[x]);
    }

    for (int i = 0; i < n; i++)
    {
        dfsroot = i;
        cntroot = 0;
        tarjan(i);
        if (cntroot > 1)
            arc.insert(i);
    }

    cout << arc.size() << " camera(s) found" << endl;

    vector<string> ans;

    for (auto i: arc)
        ans.push_back(out[i]);
    sort(all(ans));

    for (auto i: ans)
        cout << i << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    //cin >> t;
    while (cin >> n && n)
    {
        if (t++)
            cout << endl;
        cout << "City map #" << t << ": ";
        solve();
    }

}