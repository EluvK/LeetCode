/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    int numIslands(vector<vector<char>> & grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j] || grid[i][j] == '0')
                    continue;
                res++;
                queue<pair<int, int>> q;
                vis[i][j] = true;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> f = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ni = f.first + dx[k];
                        int nj = f.second + dy[k];
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj] || grid[ni][nj] == '0')
                            continue;
                        q.push(make_pair(ni, nj));
                        vis[ni][nj] = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
