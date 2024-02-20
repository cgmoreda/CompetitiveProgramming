class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
	    cin.tie(NULL);
	    cout.tie(NULL);
        int n =nums.size();
        return ((n*(n+1))>>1)-accumulate(nums.begin(),nums.end(),0);
    }
};