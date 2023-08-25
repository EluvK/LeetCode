/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 *
 * [1267] 统计参与通信的服务器
 */

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>> & grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cm(m, 0);
        vector<int> cn(n, 0);
        for (int im = 0; auto _m : grid) {
            for (int in = 0; auto _n : _m) {
                if (_n == 1) {
                    cm[im]++;
                    cn[in]++;
                }
                in++;
            }
            im++;
        }
        int ans = 0;
        for (int im = 0; auto _m : grid) {
            for (int in = 0; auto _n : _m) {
                if (_n == 1) {
                    if (!(cm[im] == 1 && cn[in] == 1)) {
                        ans++;
                    }
                }
                in++;
            }
            im++;
        }
        return ans;
    }
};
// @lc code=end
