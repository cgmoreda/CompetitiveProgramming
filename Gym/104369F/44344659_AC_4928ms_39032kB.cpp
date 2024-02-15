#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<ll>
#define vvi vector<vector<int>>
#define ii pair<int,int>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
#define ordered_set tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >


vi c;
int n, q;
vector<ordered_set > idx_color;

int bsr(int x, vector<int> &col)
{
    int l = x, r = n, mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r);
        mid >>= 1;
        int count = 0;
        for (auto i: col)
        {
            auto cl = idx_color[i].order_of_key(x);
            auto cr = idx_color[i].order_of_key(mid);
            count += cr - cl + (idx_color[i].find(mid) != idx_color[i].end());
        }
        if (count >= abs(mid - x) + 1)
        {
            l = mid + 1;
            ans = max(ans, mid);
        } else
            r = mid - 1;
    }
    return ans;

}

int bsl(int x, vector<int> &col)
{
    int l = 1, r = x, mid, ans = LONG_MAX;
    while (l <= r)
    {
        mid = (l + r);
        mid >>= 1;
        int count = 0;
        for (auto i: col)
        {
            auto cl = idx_color[i].order_of_key(mid);
            auto cr = idx_color[i].order_of_key(x);
            count += cr - cl + (idx_color[i].find(x) != idx_color[i].end());
        }
        if (count >= abs(mid - x) + 1)
        {
            r = mid - 1;
            ans = min(ans, mid);
        } else
            l = mid + 1;
    }
    return ans;

}

const int N = 5e5 + 5;
int v[N];
ll seg[4 * N];
int l, r, pos, val;

struct segmentTree
{
    void build(int p = 1, int s = 1, int e = n)
    {
        if (s == e)
        {
            seg[p] = v[s];
            return;
        }
        build(2 * p, s, (s + e) / 2);
        build(2 * p + 1, (s + e) / 2 + 1, e);
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }

    ll get(int p = 1, int s = 1, int e = n)
    {
        if (r < s || e < l)return 0;
        if (l <= s && e <= r)return seg[p];
        return get(2 * p, s, (s + e) / 2) + get(2 * p + 1, (s + e) / 2 + 1, e);
    }

    void update(int p = 1, int s = 1, int e = n)
    {
        if (s == e)
        {
            seg[p] = val;
            return;
        }
        if (pos <= (s + e) / 2) update(2 * p, s, (s + e) / 2);
        else update(2 * p + 1, (s + e) / 2 + 1, e);
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
};

void solve()
{

    cin >> n >> q;
    idx_color = vector<ordered_set >(n + 1);
    c = vector<ll>(n + 1);
    segmentTree st;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        idx_color[c[i]].insert(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    st.build();
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, col;
            cin >> idx >> col;
            idx_color[c[idx]].erase(idx);
            idx_color[col].insert(idx);
            c[idx] = col;
        } else if (type == 2)
        {
            // change value;
            cin >> pos >> val;
            st.update();
        } else if (type == 3)
        {
            int x, k;
            cin >> x >> k;
            vector<int> col;
            while (k--)
            {
                int a;
                cin >> a;
                col.push_back(a);
            }
            r = bsr(x, col);
            l = bsl(x, col);
            cout << st.get() << endl;
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
        solve();
    }

}