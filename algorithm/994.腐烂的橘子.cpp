/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>> & grid) {
        deque<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)
                    q.push_back(make_pair(i, j));
        int ans = 0;
        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop_front();
            for (int i = 0; i < 4; ++i) {
                int x = f.first + dx[i], y = f.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1) {
                        grid[x][y] = grid[f.first][f.second] + 1;
                        q.push_back(make_pair(x, y));
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    return -1;
                ans = max(ans, grid[i][j]);
            }
        }
        return ans - 2 > 0 ? ans - 2 : 0;
    }
};

// @lc code=end
