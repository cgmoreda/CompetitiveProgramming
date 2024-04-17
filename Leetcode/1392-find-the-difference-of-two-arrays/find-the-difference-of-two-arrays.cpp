class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1,mp2;
        for(auto i:nums2)
            mp2[i]++;
        for(auto i:nums1)
            mp1[i]++;

        vector<vector<int>>ret(2);
        for(auto i:nums1)
        {
            if(mp2[i]++==0)
                ret[0].push_back(i);
        }
        for(auto i:nums2)
        {
            if(mp1[i]++==0)
                ret[1].push_back(i);
        }
        return ret;
    }
};