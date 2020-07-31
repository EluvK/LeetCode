/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target) {
        int i = 0;
        if (matrix.empty() || matrix[0].empty())
            return false;
        for (; i < matrix.size() - 1; ++i) {
            if (matrix[i][0] <= target && matrix[i + 1][0] > target)
                break;
        }
        if (i == 0 && matrix[i][0] > target)
            return false;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (target == matrix[i][j])
                return true;
        }
        return false;
    }
};
// @lc code=end
