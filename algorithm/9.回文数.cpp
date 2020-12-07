/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string rx = to_string(x);
        reverse(rx.begin(), rx.end());
        return to_string(x) == rx;
    }
};
// @lc code=end
