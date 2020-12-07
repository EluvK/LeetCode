/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int> & nums, int target) {
        if (nums.empty())
            return {-1, -1};
        if (nums.size() == 1) {
            if (nums[0] != target)
                return {-1, -1};
            else
                return {0, 0};
        }
        int l = 0, r = nums.size() - 1;
        if (nums[l] > target || nums[r] < target)
            return {-1, -1};
        while ((nums[l] < target || nums[r] > target) && l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                if (nums[l] != target) {
                    l++;
                }
                if (nums[r] != target) {
                    r--;
                }
            }
        }
        if (l <= r)
            return {l, r};
        return {-1, -1};
    }
};
// @lc code=end
