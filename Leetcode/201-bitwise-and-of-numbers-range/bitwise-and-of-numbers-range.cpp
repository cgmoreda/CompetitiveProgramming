

class Solution {
public:
    int rangeBitwiseAnd(int &left, int& right) {
       
        ios_base::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);
         int g=0;
        for(int i=31;i>=0;i--)
            if((left&(1<<i))!=(right&(1<<i)))
                break;
            else if(left&(1<<i))
                    g|=1<<i;
        long long z = left^right;
        while(z&(z-1))
            z&=z-1;
            if(z){
        z<<=1;
        z-=1;}
        return (left&right)&(~z);
    
    }
};