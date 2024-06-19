class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        vector<int>tmp(bloomDay);
        sort(tmp.begin(),tmp.end());
        if(1ll*m*k>n)
            return -1;
        auto can=[&](int days)
        {
            int c1=0,c2=0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=days)
                {
                    c1++;
                }
                else 
                    c1=0;

                if(c1==k)
                    c2++,c1=0;
            }
            return c2>=m;
        };
        int l=tmp[k*m-1],r=1e9+1,mid;
        int ans=*max_element(bloomDay.begin(),bloomDay.end());
        r = ans;
        while(l<=r)
        {
            mid =(l+r)/2;
            if(can(mid))
            {
                r = mid-1;
                ans = mid;
            }
            else 
                l = mid+1;
        }
        return ans;

    }
};