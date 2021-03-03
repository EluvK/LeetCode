/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    long i = 1;
    int sum = 0;
    int countDigitOne(int n) {
        int num = n;
        while (num) {
            if (num % 10 == 0) {
                sum += (num / 10) * i;
            }
            if (num % 10 == 1) {
                sum += (num / 10) * i + (n % i) + 1;
            }
            if (num % 10 > 1) {
                sum += (num / 10) * i + i;
            }
            num /= 10;
            i *= 10;
        }
        return sum;
    }
};
// @lc code=end
