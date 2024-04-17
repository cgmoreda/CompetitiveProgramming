const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
   

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        int arr1[2][2002]{},arr2[2][2002]{}; 

        for(auto &i:nums2)
         i+=1000, arr2[1][i]++;

        for(auto &i:nums1)
           i+=1000, arr1[1][i]++;

        vector<vector<int>>ret(2);
        for(auto i:nums1)
        {
            if(arr2[1][i]++==0)
                ret[0].push_back(i-1000);
        }
        for(auto i:nums2)
        {
            if(arr1[1][i]++==0)
                ret[1].push_back(i-1000);
        }
        return ret;
    }
};