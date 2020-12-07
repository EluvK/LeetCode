/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int process(int n) {
        int res = 0;
        while (n) {
            int tmp = n % 10;
            res = res + tmp * tmp;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        map<int, int> rec;
        do {
            rec[n] = 1;
            n = process(n);
        } while (n != 1 && rec[n] != 1);
        return n == 1;
    }
};
// @lc code=end
