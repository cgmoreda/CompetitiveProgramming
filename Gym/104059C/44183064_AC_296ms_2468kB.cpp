#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

void solve()
{
    int n, q;
    cin >> n >> q;
    set<int> st;
    while (q--)
    {
        char a;
        cin >> a;
        if (a == '-')
        {
            int x;
            cin >> x;
            st.insert(x);
        } else if (a == '+')
        {
            int x;
            cin >> x;
            st.erase(st.find(x));
        } else
        {
            int x, y;
            cin >> x >> y;
            bool ok = 0;
            if (y > x)
            {
                auto id = st.lower_bound(x);
                int val = (id == st.end() ? -1 : *id);
                if (val >= x && val <= y)
                {
                    ok=0;
                } else
                {
                    ok |=1;
                }
            } else
            {
                // from left to right

                auto l = st.lower_bound(x);
                auto r = st.lower_bound(1);
                int valL = (l == st.end() ? -1 : *l);
                int valR = (r == st.end() ? -1 : *r);
                if ((valL >= x && valL <= n) || (valR >= 1 && valR <= y))
                {
                    ok=0;
                } else
                {
                    ok =1;
                }

                // from right to left

            }
            swap(x,y);
            if (y > x)
            {
                auto id = st.lower_bound(x);
                int val = (id == st.end() ? -1 : *id);
                if (val >= x && val <= y)
                {
                    ok|=0;
                } else
                {
                    ok =1;
                }
            } else
            {
                // from left to right

                auto l = st.lower_bound(x);
                auto r = st.lower_bound(1);
                int valL = (l == st.end() ? -1 : *l);
                int valR = (r == st.end() ? -1 : *r);
                if ((valL >= x && valL <= n) || (valR >= 1 && valR <= y))
                {
                    ok |= 0;
                } else
                {
                    ok =1;
                }

            }
                cout<<(ok?"possible":"impossible")<<endl;
        }
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
        solve();
    }

}