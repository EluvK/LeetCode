/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> & queens, vector<int> & king) {
        int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int sx = king[0], sy = king[1];
        vector<vector<int>> ans;
        vector<vector<int>> q(8, vector<int>(8, 0));
        for (int i = 0; i < queens.size(); ++i)
            q[queens[i][0]][queens[i][1]] = 1;
        ans.clear();
        for (int i = 0; i < 8; i++) {
            int x = sx + dx[i], y = sy + dy[i];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (q[x][y]) {
                    ans.push_back({x, y});
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }
        return ans;
    }
};
// @lc code=end
