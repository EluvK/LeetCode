/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution {
public:
    int countDigits(int num) {
        int n = num, res = 0;
        while (n) {
            int r = n % 10;
            n /= 10;
            if (num % r == 0)
                res++;
        }
        return res;
    }
};
// @lc code=end
