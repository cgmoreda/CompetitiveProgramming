class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0,j=1e5;i<=j;)
        {
            if(i*i+j*j<c)
                i++;
             else if(i*i+j*j>c)
                 j--;
             else 
                return true;
        }
        return false;
    }
};