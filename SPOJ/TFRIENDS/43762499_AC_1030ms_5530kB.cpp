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
vvi G;
vi dn, dlow, onst;
stack<int> st;
int id = 0;

void tarjan(int node)
{
    if (dn[node] != -1)return;
    dn[node] = dlow[node] = ++id;
    onst[node] = 1;
    st.push(node);

    for (auto u: G[node])
    {
        if (dn[u] == -1)
        {
            tarjan(u);
            dlow[node] = min(dlow[node], dlow[u]);
        } else if (onst[u])
        {
            dlow[node] = min(dlow[node], dlow[u]);
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

void solve()
{
    int n;
    cin >> n;
    vi cost(n + 1);
    G = vvi(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char a;
            cin >> a;
            if (a == 'Y')
                G[i].push_back(j);
        }
    }
    dn = vi(n + 1, -1);
    dlow = vi(n + 1);
    onst = vi(n + 1);
    st = stack<int>();
    for (int i = 1; i <= n; i++)
    {
        if (dn[i] == -1)
        {
            tarjan(i);
        }
    }
    set<int> s;

    ll cnt = 1, ans = 0;
    for (int i = 1; i <= n; i++)s.insert(dlow[i]);

    cout << s.size() << endl;
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
        solve();
    }

}