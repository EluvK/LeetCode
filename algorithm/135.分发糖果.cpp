/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int> & ratings) {
        vector<int> nums(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                nums[i + 1] = nums[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i] && nums[i - 1] <= nums[i]) {
                nums[i - 1] = nums[i] + 1;
            }
        }
        int ans = 0;
        for (auto c : nums)
            ans += c;
        return ans;
    }
};
// @lc code=end
