class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size(),nzeros=0;
        vector<int>&v =nums;
        int ans=0;
        for(int l=0,r=0;r<n;r++)
        {
            nzeros+=nums[r]==0;
            while(nzeros>k)
            {
                nzeros-=nums[l]==0;
                l++;
            }
            ans = max(ans,r-l+1);
        }   
        
        return ans;
    }
};