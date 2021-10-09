/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int> & nums) {
        int min_index = 0;
        if (nums.empty())
            return {};
        if (nums.size() == 1)
            return {nums[0] * nums[0]};
        while (min_index + 1 < nums.size() && nums[min_index] * nums[min_index] >= nums[min_index + 1] * nums[min_index + 1]) {
            min_index++;
        }
        vector<int> res;
        res.clear();
        res.push_back(nums[min_index] * nums[min_index]);
        int l = min_index - 1, r = min_index + 1;
        while (l >= 0 && r < nums.size()) {
            if (nums[l] * nums[l] < nums[r] * nums[r]) {
                res.push_back(nums[l] * nums[l]);
                l--;
            } else {
                res.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while (l >= 0) {
            res.push_back(nums[l] * nums[l]);
            l--;
        }
        while (r < nums.size()) {
            res.push_back(nums[r] * nums[r]);
            r++;
        }
        return res;
    }
};
// @lc code=end
