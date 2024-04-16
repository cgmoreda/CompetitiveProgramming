class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = s1.size();
        int m = s2.size();
        int gc = __gcd(n,m);
        vector<int>div;
        for(int i=1;i*i<=gc;i++)
            if(gc%i==0)
            {
                div.push_back(i);
                if(i!=gc/i)
                    div.push_back(gc/i);
            }
            
       
        sort(div.rbegin(),div.rend());
        for(auto d:div)
        {
            
            bool ok = true;
            for(int i=0;ok&&i<d;i++)
            {
                for(int j=i;ok&&j<max(n,m);j+=d)
                {
                    if(j<n)
                        ok&= s1[i]==s1[j];
                    if(j<m)
                        ok&= s1[i]==s2[j];
                }
            }
            if(ok)
                return s1.substr(0,d);
            
        }
        return "";
    }
};