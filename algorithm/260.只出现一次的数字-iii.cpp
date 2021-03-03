/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int> & nums) {
        vector<int> res(2, 0);
        long x = 0;
        for (auto n : nums) {
            x ^= n;
        }
        long mask = x & (-x);
        for (auto n : nums) {
            if (n & mask) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};
// @lc code=end
