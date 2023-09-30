/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;
        int left = money - children;
        int cnt = min(left / 7, children);
        left -= cnt * 7;
        if ((children - cnt == 1 && left == 3) || (children - cnt == 0 && left > 0))
            return cnt - 1;
        return cnt;
    }
};
// @lc code=end
