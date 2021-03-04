/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int> & nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1])
                    return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return -1;
    }
};
// @lc code=end

