/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); ++i)
            if (isalpha(s[i]) || isdigit(s[i]))
                ans += toupper(s[i]);
        int len = ans.size();
        if (ans.empty())
            return true;
        for (int i = 0; i <= len / 2; ++i)
            if (ans[i] != ans[len - i - 1])
                return false;
        return true;
    }
};

// @lc code=end
