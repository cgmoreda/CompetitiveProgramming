const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
      
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
        
        return ans-1;
    }
};