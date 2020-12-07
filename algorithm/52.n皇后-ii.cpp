/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int res_num;
    void dfs(vector<uint64_t> & Qmap, int n, int row) {
        for (int i = 0; i < n; ++i) {
            Qmap[row] |= (1 << i);
            bool flag = true;
            for (int j = 0; j < row; ++j) {
                if ((Qmap[j] & Qmap[row]) || ((Qmap[j] >> (row - j)) & Qmap[row]) || ((Qmap[j] << (row - j)) & Qmap[row])) {
                    flag = false;
                    break;
                }
            }
            if (flag && row == n - 1)
                res_num++;
            else if (flag)
                dfs(Qmap, n, row + 1);

            Qmap[row] = 0;
        }
    }
    int totalNQueens(int n) {
        res_num = 0;
        vector<uint64_t> Qmap(n, 0);
        dfs(Qmap, n, 0);
        return res_num;
    }
};
// @lc code=end
