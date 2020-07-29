/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int jump(vector<int> & nums) {
        vector<int> dp(nums.size(), nums.size());
        dp[0] = 0;
        int maxright = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = max(maxright, i + 1); j < i + 1 + nums[i] && j < nums.size(); ++j) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
            maxright = max(maxright, nums[i] + i);
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end
