 const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 11;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        for (int i = 1; i < nums.size(); i++)
            nums[i]^= nums[i-1];
        return nums.back();
    }
};