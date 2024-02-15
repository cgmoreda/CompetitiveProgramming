#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vsi vector<set<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>
vsi G;
vi dn, dlow, onst;
stack<int> st;
int id = 0;
set<int> out;
int rootch;
int dfsnode;
int pr[500500];

void tarjan(int node)
{
    if (dn[node] != -1)return;
    dn[node] = dlow[node] = ++id;
    onst[node] = 1;
    st.push(node);

    for (auto u: G[node])
    {
        pr[u] = node;
        if (dn[u] == -1)
        {
            tarjan(u);
            if (dn[node] <= dlow[u])
            {
                if (node == dfsnode)
                    rootch++;
                else
                    out.insert(node);
            }
            dlow[node] = min(dlow[node], dlow[u]);

        } else if (u != pr[node])
        {
            dlow[node] = min(dlow[node], dn[u]);
        }
    }
    if (dn[node] == dlow[node])
    {
        int u = -1;

        while (u != node)
        {
            u = st.top();
            st.pop();
            onst[u] = false;
            dlow[u] = dlow[node];
        }
    }
}

int n;

void solve()
{
    out.clear();
    G = vsi(n + 1);
    dn = vi(n + 1, -1);
    dlow = vi(n + 1);
    onst = vi(n + 1);
    st = stack<int>();
    int x, y;
    while (cin >> x && x)
    {

        string s;
        cin.ignore();
        getline(cin, s);
        stringstream line;
        line << s;
        while (line >> y)
        {
            G[y].insert(x);
            G[x].insert(y);
        }
        line.ignore();
    }


    for (int i = 1; i <= n; i++)
    {
        if (dn[i] == -1)
        {
            dfsnode = i;
            rootch = 0;
            tarjan(i);
            if (rootch > 1)
                out.insert(dfsnode);
        }
    }

    cout << out.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n && n)
    {
        solve();
    }

}