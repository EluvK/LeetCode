/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (!len)
            return 0;
        vector<int> dp(len, 0);
        for (int i = 1; i < len; ++i) {
            if (s[i] == ')') {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (pre > 0)
                        dp[i] += dp[pre - 1];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// @lc code=end
