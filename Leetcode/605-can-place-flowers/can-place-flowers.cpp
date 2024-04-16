class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0;
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for(int i=0;i<f.size();i++)
        {
            if(f[i])
                i++;
            else if(i+1>=f.size()||!f[i+1])
                x++,i++;
        }
        return x>=n;
    }
};