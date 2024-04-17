class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1=2147483647,mn2=2147483647;

        for(auto &i:nums)
        {
            if(i>mn2)
                return true;
            if(i<=mn1)
                mn1 = i;
            else 
                mn2 = min(mn2,i);
        }
        return false;
    }
};