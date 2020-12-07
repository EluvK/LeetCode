/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int r = numRows, len = s.size(), t = 0;
        vector<string> ans(r, "");
        bool flag = true;
        for (int i = 0; i < len; i++) {
            ans[t] += s[i];
            if (flag)
                t++;
            else
                t--;
            if (t == r - 1)
                flag = false;
            if (t == 0)
                flag = true;
        }
        string res;
        for (int i = 0; i < r; i++) {
            res += ans[i];
        }
        return res;
    }
};
// @lc code=end
