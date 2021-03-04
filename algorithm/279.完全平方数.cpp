/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int m = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                m = min(m, f[i - j * j]);
                f[i] = m + 1;
            }
        }
        return f[n];
    }
};
// @lc code=end
