/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (!m)
            return m;
        while (m < n)
            n &= (n - 1);
        return n;
    }
};
// @lc code=end
