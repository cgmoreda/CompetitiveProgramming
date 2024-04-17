const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
class Solution {
public:
    int maxVowels(string s, int k) {
        
        vector<int>v;
        for(auto &i:s)
            v.push_back(i=='a'||i=='e'||i=='i'||i=='o'||i=='u');

        int sum = accumulate(v.begin(),v.begin()+k-1,0ll),best=-1e9;
       
        int n = v.size();
        for(int l=0,r=k-1;r<n;r++,l++)
        {
            sum+=v[r];
            best = max(best,sum);
            sum-=v[l];
        }
        return best;
    }
};