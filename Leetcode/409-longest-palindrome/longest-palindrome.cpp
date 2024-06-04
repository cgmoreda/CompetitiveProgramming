class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]%2==0)
                ans+=2;
            
        }
        for(auto [key,val]:mp)
            if(val&1)
                return ans+1;
        return ans;
    }
};