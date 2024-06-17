class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0,j=sqrt(c)+1;i<=j;)
        {
            long long tmp = i*i+j*j;
            if(tmp<c)
                i++;
             else if(tmp>c)
                j--;
             else 
                return true;
        }
        return false;
    }
};