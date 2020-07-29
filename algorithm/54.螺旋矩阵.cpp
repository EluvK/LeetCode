/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> & matrix) {
        if (!matrix.size())
            return {};
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<int> ans;
        int i = 0, j = 0, dir = 0;
        bool next_flag = true;
        while (next_flag) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;
            int ni, nj;
            for (int k = dir; k < dir + 4; ++k) {
                next_flag = false;
                ni = i + dx[k % 4];
                nj = j + dy[k % 4];
                if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && !vis[ni][nj]) {
                    next_flag = true;
                    dir = k % 4;
                    break;
                }
            }
            if (next_flag) {
                i = ni;
                j = nj;
            }
        }
        return ans;
    }
};
// @lc code=end
