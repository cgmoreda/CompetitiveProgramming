class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ex) {
        multiset<int>ms;
        
        for(auto &i:c)
            ms.insert(i);
        
        vector<bool>ret;
        for(auto &i:c)
        {
            ms.erase(ms.find(i));
            ret.push_back(*ms.rbegin()<=i+ex);
            ms.insert(i);
        }
        return ret;
    }
};