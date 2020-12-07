/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        while (!st.empty())
            st.pop();
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{'))
                    return false;
                st.pop();
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

// @lc code=end
