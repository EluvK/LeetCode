/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        long cur = 1;
        for (int i = 0; i < rowIndex; i++) {
            cur = cur * (rowIndex - i) / (i + 1);
            ans[i + 1] = (int)cur;
        }
        return ans;
    }
};

// @lc code=end
