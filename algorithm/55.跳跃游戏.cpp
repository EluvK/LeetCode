/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool canJump(vector<int> & nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (!dp[0] && nums.size() > 1)
            return false;
        for (int i = 1; i < nums.size() - 1; ++i) {
            dp[i] = max(dp[i - 1], i + nums[i]);
            if (dp[i] == i && nums[i] == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
