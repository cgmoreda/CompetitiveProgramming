const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,n = nums.size();
        for(int l=0,r=n-1;l<r;)
        {
            if(nums[l]+nums[r]>k)
                r--;
            else if(nums[l]+nums[r]<k)
                l++;
            else
                 ans++,r--,l++; 
        }
        return ans;
    }

};