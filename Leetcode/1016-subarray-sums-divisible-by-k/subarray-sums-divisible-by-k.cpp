class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) 
            ans += mp[sum = ((sum + nums[i]) % k+k)%k]++;
        
        return ans;
    }
};