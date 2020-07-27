/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> & strs) {
        string ans = "";
        if (strs.size() == 0)
            return ans;
        if (strs.size() == 1)
            return strs[0];
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            bool flag = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() <= i || strs[j][i] != c) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans = ans + c;
            else
                break;
        }
        return ans;
    }
};

// @lc code=end
