
class Solution {
public:
    string makeGood(string s) {
        string a = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && abs(st.top() - s[i]) == 32) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            a.push_back(st.top());
            st.pop();
        }

        reverse(a.begin(), a.end());
        return a;
    }
};
