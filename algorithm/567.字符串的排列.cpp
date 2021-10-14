/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool check(std::map<char, int> const & cnt) {
        for (auto _p : cnt) {
            if (_p.second != 0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        std::map<char, int> cnt;
        for (auto c : s1)
            cnt[c]++;
        int i = 0, j = 0;
        for (i = 0; i < s1.size() && i < s2.size(); ++i) {
            cnt[s2[i]]--;
        }
        while (i != s2.size()) {
            if (check(cnt))
                return true;
            cnt[s2[i]]--;
            cnt[s2[j]]++;
            i++;
            j++;
        }
        return check(cnt);
    }
};
// @lc code=end
