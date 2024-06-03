class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        for(int i=0,j=0;i<m;i++)
        {
            while(j<n&&s[j]!=t[i])
            {
                j++;
            }
            if(j==n)
            {
                return m-i;
            }
            j++;
        }
        return 0;
    }
};