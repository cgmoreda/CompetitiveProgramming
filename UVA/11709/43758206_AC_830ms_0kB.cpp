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
    vi &dn1 = dn, &dlow1 = dlow, &onstack1 = onstack;
    stack<int> &st1 = st;
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
    map<pair<string, string>, int> mp;
    int person = 0;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        mp[{x, y}] = ++person;
    }
    id = 0;
    dn = vi(n + 2, -1);
    dlow = vi(n + 2);
    onstack = vi(n + 2);
    while (!st.empty())
        st.pop();
    G = vvi(n + 1);
    for (int i = 0; i < m; i++)
    {
        string u1, u2, v1, v2;
        cin >> u1 >> u2 >> v1 >> v2;
        G[mp[{u1, u2}]].push_back(mp[{v1, v2}]);
    }
    for (int i = 1; i < n; i++)
    {
        if (dn[i] == -1)
            tarjan(i);
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(dlow[i]);

    cout << s.size() << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("out.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while (cin >> n >> m && n )
    {
        solve();
    }
}