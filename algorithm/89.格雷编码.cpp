/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        for (int i = 0; i < ans.size(); ++i)
            ans[i] = i ^ (i >> 1);
        return ans;
    }
};
// @lc code=end
