/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int solve(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int addDigits(int num) {
        while (num >= 10)
            num = solve(num);
        return num;
        // or math problem:
        // return (num - 1) % 9 + 1;
    }
};
// @lc code=end
