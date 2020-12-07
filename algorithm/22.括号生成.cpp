/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string tmp;

    void dfs(int n, int m) {
        if (n == 0 && m == 0) {
            ans.push_back(tmp);
            return;
        }
        if (n) {
            tmp.push_back('(');
            dfs(n - 1, m + 1);
            tmp.pop_back();
        }
        if (m) {
            tmp.push_back(')');
            dfs(n, m - 1);
            tmp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        tmp.clear();
        if (n)
            dfs(n, 0);
        return ans;
    }
};

// @lc code=end
