/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>> & mat) {
        if (mat.size() == 0 || mat[0].size() == 0)
            return mat;
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), -1));
        queue<tuple<int, int, int>> q;
        for (int m = 0; m < mat.size(); ++m) {
            for (int n = 0; n < mat[m].size(); ++n) {
                if (mat[m][n] == 0) {
                    q.push({m, n, 0});
                    res[m][n] = -2;
                }
            }
        }

        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            res[get<0>(f)][get<1>(f)] = get<2>(f);

            for (auto index = 0; index < 4; ++index) {
                int nx = get<0>(f) + dx[index];
                int ny = get<1>(f) + dy[index];
                if (nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size()) {
                    continue;
                }
                if (res[nx][ny] != -1)
                    continue;

                res[nx][ny] = -2;
                if (mat[nx][ny] != 0) {
                    q.push({nx, ny, get<2>(f) + 1});
                } else {
                    q.push({nx, ny, 0});
                }
            }
        }
        return res;
    }
};
// @lc code=end
