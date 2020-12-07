/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string tmp;
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0);
        return ans;
    }
    void solve(string s, int index) {
        if (s.size() < (4 - index) || s.size() > 3 * (4 - index))
            return;
        if (index == 3 && vaild_ip(s)) {
            tmp = tmp + s;
            ans.push_back(tmp);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (s.size() < i)
                continue;
            if (!vaild_ip(s.substr(0, i)))
                continue;
            string f = tmp;
            tmp = tmp + s.substr(0, i) + ".";
            solve(s.substr(i), index + 1);
            tmp = f;
        }
    }
    bool vaild_ip(string s) {
        if (s[0] == '0' && s.size() > 1)
            return false;
        int num = atoi(s.c_str());
        if (num < 0 || num > 255)
            return false;
        return true;
    }
};
// @lc code=end
