class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int mn1=2147483647,mn2=2147483647;

        for(auto &i:nums)
        {
            if(i>mn2)
                return true;
            if(i<=mn1)
                mn1 = i;
            else if(i<mn2)
                mn2 = i;
        }
        return false;
    }
};