/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int> & heights) {
        heights.push_back(0);
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int top = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
            stk.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> & matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> matrix_int(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_int[i][j] = matrix[i][j] - '0';
                if (i && matrix_int[i][j]) {
                    matrix_int[i][j] += matrix_int[i - 1][j];
                }
            }
        }
        int ans = 0;
        for (auto vc : matrix_int) {
            ans = max(ans, largestRectangleArea(vc));
        }
        return ans;
    }
};
// @lc code=end
