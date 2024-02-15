#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
struct point{
  ll sum, i, j;

  bool operator < (const point&e )const{
      if(sum == e.sum){
          if(i == e.i){
              return j < e.j;
          }
          return i < e.i;
      }
      return sum < e.sum;
  }
};

vector<int> v;
int n;

ll solve()
{
    multiset<ll>ms;
    for(int i=0;i < n;i++){
        ms.insert(v[i]);
    }
    ll cost = 0;
    while(ms.size() > 1){
        auto cur1 = *ms.begin();
        ms.erase(ms.begin());
        auto cur2 = *ms.begin();
        ms.erase(ms.begin());
        ll val = cur1+cur2;
        cost += val;
        ms.insert({val});
    }

    return cost;
}

ll dpbr[1001][1001];

ll dopebr(int l, int r)
{
    if (l >= r)
        return 0;
    ll &ret = dpbr[l][r];
    if (~ret)
        return ret;
    ret = 1e15;
    ll sum = accumulate(v.begin() + l, v.begin() + r + 1, 0LL);
    for (int i = l; i < r; i++)
        ret = min(ret, dopebr(l, i) + dopebr(i + 1, r) + sum);

    return ret;
}


int solvebrute()
{
    memset(dpbr, -1, sizeof dpbr);
    return dopebr(0, n - 1);

}

void gen()
{
    int x = 0;
    while (true)
    {
        if (x % 10000 == 0)
            cout << "test: " << x << endl;
        x++;
        int sz = rand() % 100 + 10;
        vector<int> t(sz);
        n = sz;
        for (int i = 0; i < sz; i++)
        {
            t[i] = rand() % 100 + 1;
        }
        v = t;
        if (solvebrute() == solve())
        {
            continue;
        } else
        {
            for (auto i: v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // gen();

    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v = vi(n);
        vin(v);
        cout << solve() << endl;
    }

}