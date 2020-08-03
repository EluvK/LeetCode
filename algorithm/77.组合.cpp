/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int nmax = 1 << n;
        vector<vector<int>> ans;
        for (int i = 1; i < nmax; i++) {
            vector<int> tmp;
            if (__builtin_popcount(i) != k)
                continue;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i)
                    tmp.push_back(j + 1);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
