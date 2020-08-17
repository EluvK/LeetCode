/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> & dungeon) {
        if (dungeon.empty() || dungeon[0].empty())
            return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            dp[m - 1][i] = max(dp[m - 1][i + 1] - dungeon[m - 1][i + 1], 1);
        }
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i + 1][n - 1], 1);
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = min(max(dp[i][j + 1] - dungeon[i][j + 1], 1), max(dp[i + 1][j] - dungeon[i + 1][j], 1));
            }
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return max(dp[0][0] - dungeon[0][0], 1);
    }
};
// @lc code=end
