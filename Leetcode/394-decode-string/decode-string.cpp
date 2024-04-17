class Solution {
public:
    string decodeString(string s) {

        stack<int> st;
        stack<string> ls;

        string nm = "";
        string out, cur;
        for (auto& i : s) {
            if (i >= '0' && i <= '9') {
                nm += i;
            } else if (i == '[') {
                ls.push(cur);
                st.push(stoi(nm));
                cur = "";
                nm = "";
            } else if (i == ']') {

                string x = ls.top();
                for (int j = 0; j < st.top(); j++)
                    x += cur;

                cur = x;
                ls.pop();
                st.pop();
            } else {
                cur += i;
            }
        }
        return cur;
    }
};