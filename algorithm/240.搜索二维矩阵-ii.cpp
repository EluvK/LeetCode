/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<vector<int>> & matrix, int m, int n, int target) {
        if (m < 0 || n >= matrix[0].size())
            return false;
        if (matrix[m][n] == target)
            return true;

        else if (matrix[m][n] < target)
            return search(matrix, m, n + 1, target);
        else
            return search(matrix, m - 1, n, target);
    }
    bool searchMatrix(vector<vector<int>> & matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        return search(matrix, m - 1, 0, target);
    }
};

// @lc code=end
