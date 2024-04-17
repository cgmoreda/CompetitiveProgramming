class Solution {
public:
    void moveZeroes(vector<int>& v) {
        for(int l=0,r=0;r<v.size();l++,r++)
        {
            while(r<v.size()&&v[r]==0)
                r++;
            if(r<v.size())
                swap(v[l],v[r]);
            
        }
        return ;
    }
};