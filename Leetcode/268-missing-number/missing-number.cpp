class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);

        return (int)((nums.size()*(nums.size()+1)/2)-accumulate(nums.begin(),nums.end(),0));
    }
};