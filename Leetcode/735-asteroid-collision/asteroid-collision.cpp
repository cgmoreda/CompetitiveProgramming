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
        stack<int> st2;
        while (st.size()) {
            st2.push(st.top());
            st.pop();
        }

        while (st2.size()) {
            out.push_back(st2.top());
            st2.pop();
        }
        return out;
    }
};