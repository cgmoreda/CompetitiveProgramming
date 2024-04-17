const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.begin()+k-1,0ll),best=-1e9;
       
        int n = nums.size();
        for(int l=0,r=k-1;r<n;r++,l++)
        {
            sum+=nums[r];
            best = max(best,sum);
            sum-=nums[l];
        }
        return best/(double)k;
    }
};