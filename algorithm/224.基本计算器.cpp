/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<long> st;

        int sign = 1;
        long res = 0;
        int length = s.size();
        for (int i = 0; i < length; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                long cur = ch - '0';
                while (i + 1 < length && isdigit(s[i + 1]))
                    cur = cur * 10 + s[++i] - '0';
                res = res + sign * cur;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
            } else if (ch == ')') {
                int a = st.top();
                st.pop();
                res = a * res + st.top();
                st.pop();
            }
        }
        return (int)res;
    }
};
// @lc code=end
