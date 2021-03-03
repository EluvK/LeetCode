/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int> & nums) {
        vector<int> pre(nums.size(), 1), post(nums.size(), 1);
        for (int index = 1; index < nums.size(); index++) {
            pre[index] = pre[index - 1] * nums[index - 1];
        }
        for (int index = nums.size() - 2; index >= 0; index--) {
            post[index] = post[index + 1] * nums[index + 1];
        }
        vector<int> ans(nums.size(), 0);

        for (int index = 0; index < nums.size(); index++) {
            ans[index] = pre[index] * post[index];
        }
        return ans;
    }
};
// @lc code=end
