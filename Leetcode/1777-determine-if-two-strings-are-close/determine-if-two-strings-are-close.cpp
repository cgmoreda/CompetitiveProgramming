#define all(v) v.begin(),v.end()
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")


const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();


class Solution {
public:
    bool closeStrings(string s, string t) {
        vector<int>f1(150),f2(150);
        set<int>s1,s2;
        for(auto &i:s)
            f1[i]++,s1.insert(i);
        for(auto &i:t)
            f2[i]++,s2.insert(i);
        sort(all(f1));
        sort(all(f2));

        if(f1==f2&&s1==s2)
            return true;
        else 
            return false;
    }
};