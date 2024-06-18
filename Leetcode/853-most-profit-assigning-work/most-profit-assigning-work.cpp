class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        multiset<pair<int,int>>ms;
        for(int i=0;i<profit.size();i++)
            ms.insert({difficulty[i],profit[i]});
        
        sort(worker.begin(),worker.end());
        int p =0,ans=0;
        for(int i=0,j=0;i<worker.size();i++)
        {
            while(ms.size()&&worker[i]>=ms.begin()->first)
            {
                p = max(p,ms.begin()->second);
                ms.erase(ms.begin());
            }
            ans+=p;
        }
        return ans;
    }
};