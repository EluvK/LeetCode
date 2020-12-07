/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int> & nums) {
        int len = nums.size();
        for (int i = len - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                int mn = i;
                for (int j = i; j < len; j++) {
                    if (nums[j] > nums[i - 1] && nums[j] < nums[mn])
                        mn = j;
                }
                swap(nums[mn], nums[i - 1]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};

// @lc code=end
