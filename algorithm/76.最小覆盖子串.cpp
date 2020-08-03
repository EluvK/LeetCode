/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool check(map<char, int> & mp) {
        for (auto pir : mp) {
            if (pir.second > 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int res_l, res_r = 0x3fffffff;
        map<char, int> mp_t;
        for (auto c : t) {
            mp_t[c]++;
        }
        map<char, int> tmp_t = mp_t;
        bool flag = false;
        while (l <= r && r < s.size()) {
            char tmp = s[r];
            if (!flag && mp_t[tmp]) {
                tmp_t[tmp]--;
            }
            if (!check(tmp_t)) {
                r++;
                flag = false;
            } else {
                flag = true;
                if (res_r - res_l > r - l) {
                    res_r = r;
                    res_l = l;
                }
                if (mp_t[s[l]]) {
                    tmp_t[s[l]]++;
                }
                l++;
            }
        }
        if (res_r != 0x3fffffff)
            return s.substr(res_l, res_r - res_l + 1);
        return "";
    }
};
// @lc code=end
