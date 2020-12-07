/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int> & nums, int k) {
        std::rotate(nums.rbegin(), nums.rbegin() + k % nums.size(), nums.rend());

        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k + 1, nums.end());
    }
};
// @lc code=end
