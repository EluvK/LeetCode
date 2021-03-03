/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int> & nums) {
        nums.push_back(-1);
        for (int index = 0; index < nums.size(); ++index) {
            while (nums[index] != -1 && nums[index] != index) {
                swap(nums[index], nums[nums[index]]);
            }
        }
        for (int index = 0; index < nums.size(); ++index) {
            if (nums[index] == -1)
                return index;
        }
        return -1;
    }
};
// @lc code=end
