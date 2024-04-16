class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int>pref(nums),suf(nums);
        for(int i=1;i<n;i++)
            pref[i] *=pref[i-1];
        for(int i=n-2;i>=0;i--)
            suf[i] *=suf[i+1];
        vector<int>ret(n);
        for(int i=0;i<n;i++)
        {
            int &ans = ret[i]=1;
            if(i)
                ans*=pref[i-1];
            if(i!=n-1)
                ans*=suf[i+1];
        }
        return ret;
    }
};