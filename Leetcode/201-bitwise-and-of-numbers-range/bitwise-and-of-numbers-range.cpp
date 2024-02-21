//Mohamed_Reda
class Solution {
public:
    int rangeBitwiseAnd(int& left, int& right) {
        unsigned int z = left^right;
        while(z&(z-1))z&=z-1;
        if(z)z<<=1,z-=1;
        return (left&right)&(~z);
    }
};