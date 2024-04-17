class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp,mp2;
        for(auto &i:arr)
            mp[i]++;
        for(auto [k,f]:mp)
            if(mp2[f]++)
                return false;
        return true;   
    }
};