

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
     
        unsigned int z = left^right;
        while(z&(z-1))
            z&=z-1;
        if(z){
            z<<=1,z-=1;
        }
        return (left&right)&(~z);
    
    }
};