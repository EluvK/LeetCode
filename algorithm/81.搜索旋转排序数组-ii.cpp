/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool search(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        return binary_search(nums.begin(), nums.end(), target);
    }
};
// @lc code=end
