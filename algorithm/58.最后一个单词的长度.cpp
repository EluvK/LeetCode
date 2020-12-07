/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    static inline void rtrim(std::string & s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
    }
    int lengthOfLastWord(string s) {
        rtrim(s);
        reverse(s.begin(), s.end());
        int ans = 0;
        for (auto c : s) {
            if (c == ' ')
                break;
            ans++;
        }
        return ans;
    }
};
// @lc code=end
