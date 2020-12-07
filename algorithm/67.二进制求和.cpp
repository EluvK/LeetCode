/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool up_flag = false;
        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            int nxt = (a[i] - '0') + (b[i] - '0') + (up_flag ? 1 : 0);
            up_flag = nxt > 1 ? true : false;
            nxt %= 2;
            ans = ans + to_string(nxt);
        }
        if (a.size() > b.size()) {
            int i = b.size();
            while (i < a.size()) {
                int nxt = (a[i] - '0') + (up_flag ? 1 : 0);
                up_flag = nxt > 1 ? true : false;
                nxt %= 2;
                ans = ans + to_string(nxt);
                i++;
            }
        }
        if (b.size() > a.size()) {
            int i = a.size();
            while (i < b.size()) {
                int nxt = (b[i] - '0') + (up_flag ? 1 : 0);
                up_flag = nxt > 1 ? true : false;
                nxt %= 2;
                ans = ans + to_string(nxt);
                i++;
            }
        }
        if (up_flag)
            ans = ans + "1";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
