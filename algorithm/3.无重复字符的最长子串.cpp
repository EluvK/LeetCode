/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 1)
            return 0;
        int ans = 1, len = s.length();
        vector<int> dp(len, 0);
        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 1; j >= i - dp[i - 1]; j--) {
                if (s[i] == s[j]) {
                    dp[i] = i - j;
                    break;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// @lc code=end
