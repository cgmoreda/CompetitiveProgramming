class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0;
        for(int i=0;i<f.size();)
        {
            if(f[i])
            {
                i+=2;
            }
            else if(i+1>=f.size()||!f[i+1]) {
                x++;
                i+=2;
            }
            else 
                i++;
        }
        return x>=n;
    }
};