/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int cnt[26] = {0};
        for (auto index = 0; index < s.size(); ++index) {
            cnt[s[index] - 'a']++;
            cnt[t[index] - 'a']--;
        }
        for (auto index = 0; index < 26; ++index) {
            if (cnt[index])
                return false;
        }
        return true;
    }
};
// @lc code=end
