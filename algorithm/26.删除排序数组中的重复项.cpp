/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        if (nums.size() < 2)
            return nums.size();
        int j = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[j] != nums[i])
                nums[++j] = nums[i];
        }
        return ++j;
    }
};

// @lc code=end
