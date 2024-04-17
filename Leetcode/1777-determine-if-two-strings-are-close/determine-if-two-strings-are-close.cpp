#define all(v) v.begin(),v.end()
class Solution {
public:
    bool closeStrings(string s, string t) {
        vector<int>f1(150),f2(150);
        set<int>s1,s2;
        for(auto &i:s)
            f1[i]++,s1.insert(i);
        for(auto &i:t)
            f2[i]++,s2.insert(i);
        sort(all(f1));
        sort(all(f2));

        if(f1==f2&&s1==s2)
            return true;
        else 
            return false;
    }
};