/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        for (int i = 2; i < nums.size();) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                nums.erase(nums.begin() + i);
            } else {
                ++i;
            }
        }
        return nums.size();
    }
};
// @lc code=end
