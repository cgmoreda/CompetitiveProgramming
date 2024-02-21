

class Solution {
public:
    int rangeBitwiseAnd(int &left, int& right) {
        int g=0;
        
        for(int i=31;i>=0;i--)
            if((left&(1<<i))!=(right&(1<<i)))
                break;
            else {
                if(left&(1<<i))
                {
                    g|=1<<i;
                }
            }
            return g;
    }
};