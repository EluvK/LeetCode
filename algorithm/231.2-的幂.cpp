/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) { return n != INT_MIN && __builtin_popcount(n) == 1; }
};
// @lc code=end

