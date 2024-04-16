class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = 0, m = f.size();
        for(int i=0;i<m;)
        {
            if(f[i])
                i+=2;
            else if(i+1>=m||!f[i+1])
                x++,i+=2;
            else 
                i++;
        }
        return x>=n;
    }
};