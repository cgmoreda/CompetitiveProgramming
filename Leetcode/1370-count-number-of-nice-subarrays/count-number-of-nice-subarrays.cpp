class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a(n+2),b(n+2),o;
        int c=0;

        for(int i=0;i<n;i++)
        {
            c++;
            if(nums[i]&1)
            {
                o.push_back(i);
                b[i]=c;
                c=0;
            }
            
        }
        c=0;
        for(int i=n-1;i>=0;i--)
        {
            c++;
            if(nums[i]&1)
            {
                a[i]=c;
                c=0;
            }
        }
        int ans=0;
        for(int i=0;i+k-1<o.size();i++)
            ans+=b[o[i]]*a[o[i+k-1]];
 
        return ans;
    }
};