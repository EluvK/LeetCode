/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>> & matrix) {
        int m = matrix.size();
        if (!m)
            return 0;
        int n = matrix[0].size();
        if (!n)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};

// @lc code=end
