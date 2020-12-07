/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int exp) {
        long n = exp;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1, c = x;
        for (long i = n; i != 0; i >>= 1) {
            if (i % 2)
                ans *= c;
            c *= c;
        }
        return ans;
    }
};

// @lc code=end
