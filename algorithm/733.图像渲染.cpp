/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor) {
        if (image.size() == 0 || image[0].size() == 0)
            return image;
        if (image[sr][sc] == newColor)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int ori = image[sr][sc];
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            image[f.first][f.second] = newColor;
            for (auto index = 0; index < 4; ++index) {
                auto nx = f.first + dx[index];
                auto ny = f.second + dy[index];
                if (nx < 0 || nx >= image.size() || ny < 0 || ny >= image[0].size()) {
                    continue;
                }
                if (image[nx][ny] == ori) {
                    image[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
// @lc code=end
