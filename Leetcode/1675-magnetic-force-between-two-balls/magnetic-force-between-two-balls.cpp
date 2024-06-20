class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        
	    ios_base::sync_with_stdio(false);
	    cin.tie(nullptr);
        
        int n = position.size();
        sort(position.begin(),position.end());
        auto can=[&](int d){
            int pr = position[0];
            int cnt=1;
            for(int i=0;i<n;i++)
            {
                if(position[i]-pr>=d)
                {
                    pr = position[i];
                    cnt++;
                }
            }
            return cnt>=m;
        };
        int l=0,r=1e9,ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(can(mid))
            {
                l = mid+1;
                ans = mid;
            }
            else 
                r = mid-1;
        }
        return ans;
    }
};