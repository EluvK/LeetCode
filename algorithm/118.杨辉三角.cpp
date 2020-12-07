/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> tmp(i, 1);
            ans.push_back(tmp);
        }
        for (int i = 2; i < numRows; ++i) {
            int cnt = i + 1;
            for (int j = 1; j < cnt - 1; ++j) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};
// @lc code=end
