class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n0=0,n1=0;
      n0 = count(nums.begin(),nums.end(),0);
      n1 = count(nums.begin(),nums.end(),1);
      for(int i=0;i<nums.size();i++)
        nums[i]=(i>=n0)+(i>=n0+n1);
      
    }
};