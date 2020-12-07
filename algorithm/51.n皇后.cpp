/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    void setresult(vector<uint64_t> const & Qmap) {
        vector<string> ans;
        for (int i = 0; i < Qmap.size(); ++i) {
            string tmp{};
            uint64_t num = Qmap[i];
            for (int j = 0; j < Qmap.size(); ++j) {
                int tmp_res = num & 1;
                tmp = tmp + (tmp_res ? "Q" : ".");
                num = num >> 1;
            }
            ans.push_back(tmp);
        }
        res.push_back(ans);
    }
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
                setresult(Qmap);
            else if (flag)
                dfs(Qmap, n, row + 1);

            Qmap[row] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<uint64_t> Qmap(n, 0);
        res.clear();
        dfs(Qmap, n, 0);
        return res;
    }
};
// @lc code=end
