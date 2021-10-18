/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    void do_dfs(std::string & s, std::size_t index) {
        if (index == s.size()) {
            res.push_back(s);
            return;
        }
        if (isalpha(s[index])) {
            auto _s = s;
            if (isupper(s[index])) {
                _s[index] = tolower(_s[index]);
            } else {
                _s[index] = toupper(_s[index]);
            }
            do_dfs(s, index + 1);
            do_dfs(_s, index + 1);
        } else {
            do_dfs(s, index + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        do_dfs(s, 0);
        return res;
    }
};
// @lc code=end
