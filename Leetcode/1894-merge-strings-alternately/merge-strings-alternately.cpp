class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out;
        int n = word1.size();
        int m = word2.size();
        for(int i=0;i<max(n,m);i++)
        {
            if(i<n)
                out.push_back(word1[i]);
            if(i<m)
                out.push_back(word2[i]);
        }
        return out;
    }
};