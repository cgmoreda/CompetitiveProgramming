class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n =nums.size();
        vector<int>pref(nums),suf(nums),ret(n,1);
        
        for(int i=n-2;i>=0;i--){
            suf[i] *=suf[i+1];
            ret[i]*=suf[i+1];
        }
        for(int i=1;i<n;i++)
        {
            pref[i] *=pref[i-1];
            ret[i]*=pref[i-1];
        }
        return ret;
    }
};