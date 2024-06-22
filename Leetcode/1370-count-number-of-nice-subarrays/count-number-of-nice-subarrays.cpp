class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>b(n+2),o;
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
        o.push_back(n);
        b[n] = c+1;
        int ans=0;
        for(int i=0;i+k<o.size();i++)
            ans+=b[o[i]]*b[o[i+k]];
 
        return ans;
    }
};