#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll long long
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>


class DSU
{
private:
    vi p, rank;
public:
    DSU(int N)
    {
        rank.assign(N + 1, 0);
        p.assign(N + 1, 0);
        for (int i = 0; i <= N; i++)
            p[i] = i;
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void join(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            } else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

};
bool comp(int x,int y)
{
    int f1=x%10;
    int f2=x/10;
    int s1=y%10;
    int s2=y/10;
    if(max(f1,f2)==max(s1,s2))return min(f1,f2)<min(s1,s2);
    return max(f1,f2)<max(s1,s2);
}
int n;
vector<int>prob;
void solve()
{
    int freq[10];
    for(int i=0;i<10;i++)cin>>freq[i];
    string last;
    bool ok=false;
    string ans;
    for(int i=0;i<n;i++)
    {
        int f1=prob[i]%10;
        int f2=prob[i]/10;
        if(f1!=f2&&freq[f1]&&freq[f2]
           ||f1==f2&&freq[f1]>=2)
        {
            ok=true;
            last+=to_string(f2);
            last+=to_string(f1);
            freq[f1]--;
            freq[f2]--;
            break;
        }
    }
    if(ok)
    {
        for(int i=9;i>=0;i--)while(freq[i]--)ans+=to_string(i);
        ans+=last;
        reverse(all(ans));
        while(ans.size()>1&&ans.back()=='0')ans.pop_back();
        reverse(all(ans));
        cout<<ans<<endl;
    }
    else if(freq[8])cout<<8<<endl;
    else if(freq[4])cout<<4<<endl;
    else if(freq[0])cout<<0<<endl;
    else cout<<-1<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=96;i>=0;i-=4)
    {
        int rev=0;
        rev+=i%10;
        rev*=10;
        rev+=i/10;
        if(rev%4==0&&rev>i)continue;
        prob.push_back(i);
    }
    sort(all(prob),comp);
    n=prob.size();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

}