#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define watch(x) cout << (#x)<<" = "<<x<<endl
#define sz(s)    (int)(s.size())
#define endl '\n'
#define aftarpoint cout<<fixed <<setprecision(9);
#define popCnt(x) (__builtin_popcountll(x))
typedef long long ll;


void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}


void myMain()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    set<int> tog, alone;
    set<pair<int, int>> take_alone;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first >= v[i].second)
            tog.insert(i);
        else
        {
            alone.insert(i);
            take_alone.insert({{v[i].second - v[i].first}, i});
        }
    }

    while (sz(take_alone) && sz(alone) && (sz(alone) * 2) + sz(tog) > m)
    {
        auto cur = *take_alone.begin();
        take_alone.erase(take_alone.begin());
        int idx = cur.second;
        tog.insert(idx);
        alone.erase(alone.find(idx));
    }

    if (sz(tog) == 1)
    {
        int idx = *tog.begin();
        int cur = v[idx].first - v[idx].second;
        if (sz(take_alone))
        {
            auto val = *take_alone.begin();
            take_alone.erase(take_alone.begin());
            if (val.first <= cur)
            {
                int id = val.second;
                alone.erase(alone.find(id));
                tog.insert(id);
            } else
            {
                int curV = *tog.begin();
                tog.erase(tog.begin());
                alone.insert(curV);
            }
        } else
        {
            int cur = *tog.begin();
            tog.erase(tog.begin());
            alone.insert(cur);
        }
    }
    ll ans = 0;
    while (sz(tog))
    {
        int cur = *tog.begin();
        tog.erase(tog.begin());
        ans += v[cur].first;
    }
    while (sz(alone))
    {
        int cur = *alone.begin();
        alone.erase(alone.begin());
        ans += v[cur].second;
    }
    cout << ans << endl;
}

int main()
{
    //aftarpoint;
    fast();
    int t = 1;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        //cout << "Case #" << T << ": ";
        myMain();
    }
    return 0;
}