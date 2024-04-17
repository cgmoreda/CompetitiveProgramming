class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ele = 0;
        for (int i = 0; i < nums.size(); i++)
            ele ^= nums[i];
        return ele;
    }
};