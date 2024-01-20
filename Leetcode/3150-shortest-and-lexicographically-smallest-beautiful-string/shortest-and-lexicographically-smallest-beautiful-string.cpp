class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        if(count(s.begin(),s.end(),'1')<k)
            return "";
        int n = s.size();
        int len=1001;
        string ans="zby";

        
        for(int i=0;i<n;i++)
        {
            string tmp="";
            int cnt=0,tlen=0;
            for(int j=i;j<n;j++)
            {
                tmp+=s[j];
                tlen++;
                cnt+=('1'==s[j]);
                if(cnt==k&&len>=tlen)
                {
                    if(len>tlen)
                        ans = tmp;
                    
                    len = min(len,tlen);
                    
                    ans = min(tmp,ans);
                    break;
                }
            }
        }
     
        return ans;
    }
};