/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ans = "", hex = "0123456789abcdef";
        while (num && (ans.size() < 8)) {
            ans = hex[num & 0xf] + ans;
            num >>= 4;
        }
        return ans;
    }
};
// @lc code=end
