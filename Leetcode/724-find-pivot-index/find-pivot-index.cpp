class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0ll);
     
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
            if(i)
                nums[i]+=nums[i-1];
            
            if((i==0&&sum==0)||(i&&sum==nums[i-1]))
                return i;
        }
        return -1;
    }
};