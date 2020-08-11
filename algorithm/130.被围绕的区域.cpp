/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>> & board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push(make_pair(i, 0));
                vis[i][0] = true;
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                q.push(make_pair(i, n - 1));
                vis[i][n - 1] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                q.push(make_pair(0, j));
                vis[0][j] = true;
            }
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) {
                q.push(make_pair(m - 1, j));
                vis[m - 1][j] = true;
            }
        }

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = f.first + dx[k], nj = f.second + dy[k];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;
                if (vis[ni][nj] || board[ni][nj] == 'X')
                    continue;
                vis[ni][nj] = true;
                q.push(make_pair(ni, nj));
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
// @lc code=end
