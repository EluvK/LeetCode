/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string temp;
    void dfs(string str) {
        if (str.size() == 0) {
            ans.push_back(temp);
            return;
        }
        int ind = str[0] - '0';
        for (int i = 0; i < v[ind].size(); ++i) {
            temp.push_back(v[ind][i]);
            dfs(str.substr(1));
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        temp.clear();
        if (digits.size())
            dfs(digits);
        return ans;
    }
};

// @lc code=end
