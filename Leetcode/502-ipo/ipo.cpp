class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        multiset<int>in;
        multiset<pair<int,int>>out;
        int n = capital.size();
        for(int i=0;i<n;i++)
        {
            if(capital[i]>w)
                out.insert({capital[i],i});
            else
                in.insert(profit[i]);
        }
        for(int i=0;i<k;i++)    
        {
            if(in.empty())
                {
                    break;
                }
            w+=*in.rbegin();
            in.erase(in.find(*in.rbegin()));
            while(out.size()&& out.begin()->first<=w)
            {
                in.insert(profit[out.begin()->second]);
                out.erase(out.begin());
            }
        }
        return w;
    }
};