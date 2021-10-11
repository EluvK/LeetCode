/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        auto iter = s.begin();
        while (iter != s.end()) {
            auto end_iter = find(iter, s.end(), ' ');
            if (end_iter == s.end()) {
                reverse(iter, s.end());
                return s;
            }
            reverse(iter, end_iter);
            iter = ++end_iter;
        }
        return s;
    }
};
// @lc code=end
