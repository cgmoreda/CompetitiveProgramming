class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n =nums.size();
        vector<int>pref(n,1),suf(n,1),ret(n,1);
        
        pref[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            pref[i] =pref[i-1]*nums[i];
            ret[i]*=pref[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            suf[i] =suf[i+1]*nums[i];
            ret[i]*=suf[i+1];
        }
        return ret;
    }
};