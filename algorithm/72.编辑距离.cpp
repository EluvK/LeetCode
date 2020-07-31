/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int dp[1010][1010];
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if (l1 == 0)
            return l2;
        if (l2 == 0)
            return l1;
        for (int i = 0; i <= l1; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= l2; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[l1][l2];
    }
};
// @lc code=end
