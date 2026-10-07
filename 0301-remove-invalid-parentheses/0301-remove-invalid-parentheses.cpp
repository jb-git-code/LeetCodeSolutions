class Solution {
public:
    unordered_set<string> st;
    int maxLen = -1;

    vector<string> removeInvalidParentheses(string s) {
        string str = "";
        solve(s, 0, 0, str);
        return vector<string>(st.begin(), st.end());
    }

    void solve(string& s, int i, int count, string& str) {
        if (count < 0)
            return;
        if (i == (int)s.size()) {
            if (count == 0) {
                if ((int)str.size() > maxLen) {
                    maxLen = str.size();
                    st.clear();
                }
                if ((int)str.size() == maxLen)
                    st.insert(str);
            }
            return;
        }
        char c = s[i];
        if (c != '(' && c != ')') {
            str.push_back(c);
            solve(s, i + 1, count, str);
            str.pop_back();
        } else {
            str.push_back(c);
            solve(s, i + 1, count + (c == ')' ? -1 : 1), str);
            str.pop_back();
            solve(s, i + 1, count, str);
        }
    }
};