class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp,mp2;
        for(auto &i:arr)
         mp[i]++;
        for(auto [x,y]:mp)
            if(mp2[y]++)
            return false;
        return true;   
    }
};