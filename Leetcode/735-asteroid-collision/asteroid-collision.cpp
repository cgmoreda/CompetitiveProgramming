#define all(v) v.begin(), v.end()
const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 11;
}();


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out,st;

        for (auto& i : asteroids) {
            if (i < 0) {
                while (st.size() && st.back() < -i)
                    st.pop_back();
                if (st.empty()) {
                    out.push_back(i);
                } else if (st.back() == -i) {
                    st.pop_back();
                }
            } else {
                st.push_back(i);
            }
        }
        
      
        for (auto i : st)
            out.push_back(i);
        return out;
    }
};