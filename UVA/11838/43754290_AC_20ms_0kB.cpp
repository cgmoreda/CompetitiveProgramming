#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define ii pair<int,int>
int n, m;
vvi G;
const int N = 2200;
vi dn, dlow, onstack;
stack<int> st;
int id = 0;

void tarjan(int node)
{
    if (~dn[node])return;
    ++id;
    dn[node] = dlow[node] = id;
    onstack[dn[node]] = 1;
    st.push(node);

    for (auto u: G[node])
    {
        if (dn[u] == -1)
        {
            tarjan(u);
            dlow[node] = min(dlow[node], dlow[u]);
        }
        if (onstack[dn[u]])
            dlow[node] = min(dlow[node], dlow[u]);
    }
    if (dlow[node] == dn[node])
    {
        int u = -1;
        while (u != node)
        {
            u = st.top();
            st.pop();
            onstack[dn[u]] = 0;
            dlow[u] = dlow[node];
        }
    }
}

void solve()
{
    id = 0;
    dn = vi(N, -1);
    dlow = vi(N);
    onstack = vi(N);
    while (!st.empty())
        st.pop();
    G = vvi(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        G[u].push_back(v);
        if (x == 2)
            G[v].push_back(u);
    }
    tarjan(1);
    for (int i = 1; i <= n; i++)
        if (dlow[i] != 1)
        {
            cout << 0 << endl;
            return;
        }

    cout << 1 << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n >> m && n && m)
    {
        solve();
    }

}