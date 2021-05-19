/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> s;
    NumMatrix(vector<vector<int>> & matrix) {
        int m = matrix.size();
        if (m) {
            int n = matrix[0].size();
            s = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
            for (auto mi = 1; mi <= m; ++mi) {
                for (auto ni = 1; ni <= n; ++ni) {
                    s[mi][ni] += s[mi - 1][ni] + s[mi][ni - 1] - s[mi - 1][ni - 1] + matrix[mi - 1][ni - 1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) { return s[row2 + 1][col2 + 1] + s[row1][col1] - s[row1][col2 + 1] - s[row2 + 1][col1]; }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
