/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k) {
        unordered_map<int, int> mp;
        if (nums.empty())
            return false;
        for (int i = 0; i <= min(static_cast<int>(nums.size() - 1), k); ++i) {
            if (++mp[nums[i]] == 2) {
                return true;
            }
        }
        for (int i = k + 1; i < nums.size(); ++i) {
            mp[nums[i - k - 1]]--;
            if (++mp[nums[i]] == 2) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
