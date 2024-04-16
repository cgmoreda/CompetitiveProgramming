class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0;
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