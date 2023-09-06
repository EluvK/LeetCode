/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

// @lc code=start
class Solution {
public:
    int minNumber(vector<int> & nums1, vector<int> & nums2) {
        int ans = 99;
        for (auto a : nums1) {
            for (auto b : nums2) {
                if (a == b)
                    ans = min(ans, a);
                else
                    ans = min(ans, min(a * 10 + b, a + b * 10));
            }
        }
        return ans;
    }
};
// @lc code=end
