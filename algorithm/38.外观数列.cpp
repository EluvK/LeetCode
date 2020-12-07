/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string read(string s) {
        int i = 0, j = 0;
        string ans;
        while (i < s.size()) {
            while (j < s.size() && s[j] == s[i])
                j++;
            ans.push_back(j - i + '0');
            ans.push_back(s[i]);
            i = j;
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        while (--n)
            ans = read(ans);
        return ans;
    }
};

// @lc code=end
