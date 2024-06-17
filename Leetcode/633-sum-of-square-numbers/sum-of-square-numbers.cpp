class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long>sqrs;
        for(long long i=0;i*i<=1e10;i++)
        {
            sqrs.push_back(i*i);
        }
        
        for(auto i:sqrs)
        {
            if(c<i)
                break;
            if(binary_search(sqrs.begin(),sqrs.end(),c-i))
                return true;
            
        }
        return false;
    }
};