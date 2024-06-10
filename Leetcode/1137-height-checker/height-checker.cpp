class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ex(heights);
        sort(ex.begin(),ex.end());
        int cnt=0;
        for(int i=0;i<ex.size();i++)
            cnt+=heights[i]!=ex[i];
        return cnt;
    }
};