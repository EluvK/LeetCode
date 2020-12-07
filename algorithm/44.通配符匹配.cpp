/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= len2; ++j) {
            if (p[j - 1] == '*')
                dp[0][j] = true;
            else
                break;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    dp[i][j] = true;
                }
                if (p[j - 1] == '*' && (dp[i - 1][j] || dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        // for (auto v : dp) {
        //     for (auto c : v) {
        //         printf("%d ", c ? 1 : 0);
        //     }
        //     printf("\n");
        // }
        // printf("\n\n");
        return dp[len1][len2];
    }
};
// @lc code=end