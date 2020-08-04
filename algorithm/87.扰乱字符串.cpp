/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        unordered_map<char, int> mp;
        for (auto c : s1)
            mp[c]++;
        for (auto c : s2)
            mp[c]--;
        for (auto pr : mp)
            if (pr.second)
                return false;
        for (int i = 1; i < s1.size(); ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i))))
                return true;
        }
        return false;
    }
};
// @lc code=end
