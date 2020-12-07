/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    // why max_heap...
    int findKthLargest(vector<int> & nums, int k) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n - k, nums.begin() + n);
        return nums[n - k];
    }
};
// @lc code=end
