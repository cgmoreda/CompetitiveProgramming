class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n0=0,n1=0;
      for(auto i:nums)
        n0+=i==0,n1+=i==1;
      for(int i=0;i<nums.size();i++)
        nums[i]=(i>=n0)+(i>=n0+n1);
      
    }
};