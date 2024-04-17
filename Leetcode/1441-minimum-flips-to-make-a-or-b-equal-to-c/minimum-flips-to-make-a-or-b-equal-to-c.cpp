class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=30;i>=0;i--)
        {
            if(c&(1<<i))
            {
                if(b&(1<<i)||a&(1<<i))
                    continue;
                ans++;
            }
            else{
                
                if(b&(1<<i))
                    ans++;
                if(a&(1<<i))
                    ans++;
            }
        }
        return ans;
    }
};