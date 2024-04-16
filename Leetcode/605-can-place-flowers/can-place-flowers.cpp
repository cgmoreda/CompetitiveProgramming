class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0, m = f.size();
        for(int i=0;i<m&&n>x;i++)
        {
            if(f[i])
                i++;
            else if(i+1>=m||!f[i+1])
                x++,i++;
        }
        return x>=n;
    }
};