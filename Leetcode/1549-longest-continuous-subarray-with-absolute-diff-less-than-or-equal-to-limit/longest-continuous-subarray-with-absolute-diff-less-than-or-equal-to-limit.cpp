class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int ans = 1;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (ms.size() >= 2 && (*ms.rbegin() - *ms.begin()) > limit) {
                ms.erase(ms.find(nums[l++]));
            }
            ans = max(ans, r - l );
            ms.insert(nums[r]);
            if (!(ms.size() >= 2 && (*ms.rbegin() - *ms.begin()) > limit))
                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};