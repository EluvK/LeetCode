/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int a = 1, b = 2;
        for (int i = 2; i < n; ++i) {
            a = a + b;
            swap(a, b);
        }
        return b;
    }
};
// @lc code=end
