const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 11;
}();

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (auto& i : s) {
            if (i != '*') 
                st.push(i);
            else 
                st.pop();
        }
        string out;
        while (st.size())
            out.push_back(st.top()),st.pop();
        reverse(out.begin(), out.end());
        return out;
    }
};