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
vi dn, dlow, onst, pr;
stack<int> st;
int id = 0;
set<pair<int, int>> out;


void tarjan(int node)
{
    if (dn[node] != -1)
        return;
    dn[node] = dlow[node] = ++id;
    onst[node] = 1;
    st.push(node);

    for (auto u: G[node])
    {
        if (dn[u] == -1)
        {
            pr[u] = node;
            tarjan(u);
            if (dn[node] < dlow[u])
            {
                out.insert({min(node, u), max(node, u)});
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
    pr = vi(n + 1, -1);
    G = vsi(n + 1);
    dn = vi(n + 1, -1);
    dlow = vi(n + 1);
    onst = vi(n + 1);
    st = stack<int>();
    int x, y;
    int n2 = n;
    while (n2-- && cin >> x)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        stringstream line;
        line << s;
        string tmp;
        line >> tmp;
        while (line >> y)
        {
            G[y].insert(x);
            G[x].insert(y);
        }
        line.ignore();
    }


    for (int i = 0; i < n; i++)
    {
        if (dn[i] == -1)
        {
            tarjan(i);
        }
    }

    cout << out.size() << " critical links" << endl;
    for (auto i: out)
    {
        cout << i.first << " - " << i.second << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (cin >> n)
    {
        solve();
    }

}