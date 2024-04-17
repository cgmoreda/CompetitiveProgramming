const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();

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