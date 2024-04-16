class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ex) {


        int mx = *max_element(c.begin(),c.end());
            
        vector<bool>ret;
        for(auto &i:c)
            ret.push_back(i==mx?true:mx<=i+ex);
        
        return ret;
    }
};