/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
class Solution {
public:
    bool checkValidGrid(vector<vector<int>> & grid) {
        if (grid[0][0] != 0)
            return false;
        const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool check = false;
                for (int _ = 0; _ < 8; ++_) {
                    int nx = i + dx[_];
                    int ny = j + dy[_];
                    if (nx >= n || ny >= n || nx < 0 || ny < 0)
                        continue;
                    if (grid[nx][ny] == grid[i][j] + 1 || grid[i][j] == n * n - 1) {
                        check = true;
                        break;
                    }
                }
                if (!check)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
