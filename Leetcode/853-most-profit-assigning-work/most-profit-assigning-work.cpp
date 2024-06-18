class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>ms;
        for(int i=0;i<profit.size();i++)
            ms.push({difficulty[i],profit[i]});
        
        sort(worker.begin(),worker.end());
        int p =0,ans=0;
        for(int i=0,j=0;i<worker.size();i++)
        {
            while(ms.size()&&worker[i]>=ms.top().first)
                p = max(p,ms.top().second),ms.pop();
            
            ans+=p;
        }
        return ans;
    }
};