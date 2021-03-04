/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    const int dx[3] = {1, 0, -1};
    const int dy[3] = {1, 0, -1};
    void gameOfLife(vector<vector<int>> & board) {
        if (board.empty())
            return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> res = board;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int px = 0; px < 3; ++px) {
                    for (int py = 0; py < 3; ++py) {
                        if (px == 1 && py == 1)
                            continue;
                        int ni = i + dx[px], nj = j + dy[py];
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                            continue;
                        if (board[ni][nj])
                            cnt++;
                    }
                }
                if (cnt < 2)
                    res[i][j] = 0;
                if ((cnt == 2 || cnt == 3) && board[i][j] == 1)
                    res[i][j] = 1;
                if (cnt > 3)
                    res[i][j] = 0;
                if (cnt == 3)
                    res[i][j] = 1;
            }
        }
        board = res;
        return;
    }
};
// @lc code=end
