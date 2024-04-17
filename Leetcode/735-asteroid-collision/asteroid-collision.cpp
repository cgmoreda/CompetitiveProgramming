#define all(v) v.begin(), v.end()
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out;
        stack<int> st;

        for (auto& i : asteroids) {
            if (i < 0) {
                while (st.size() && st.top() < -i)
                    st.pop();

                if (st.empty()) {
                    out.push_back(i);
                } else if (st.top() == -i) {
                    st.pop();
                }
            } else {
                st.push(i);
            }
        }
        vector<int> out2;
        while (st.size()) {
            out2.push_back(st.top());
            st.pop();
        }
        reverse(all(out2));
        for (auto i : out2)
            out.push_back(i);
        return out;
    }
};