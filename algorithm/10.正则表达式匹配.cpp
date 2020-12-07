/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        bool first = (!s.empty()) && ((s[0] == p[0]) || (p[0] == '.'));

        if (p.size() > 1 && p[1] == '*') {
            return (bool)(isMatch(s, p.substr(2)) || (first && isMatch(s.substr(1), p)));
        } else
            return first && isMatch(s.substr(1), p.substr(1));
    }
};

// @lc code=end
