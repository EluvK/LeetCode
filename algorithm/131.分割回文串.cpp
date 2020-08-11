/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
    bool check(string cur) {
        string rev = cur;
        reverse(cur.begin(), cur.end());
        return rev == cur;
    }
    void dfs(string s, string str, vector<string> tmp_v, int index) {
        if (index == s.size()) {
            result.push_back(tmp_v);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            str += s[i];
            if (check(str)) {
                tmp_v.push_back(str);
                dfs(s, "", tmp_v, i + 1);
                tmp_v.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        if (!s.size())
            return result;
        dfs(s, "", vector<string>{}, 0);
        return result;
    }
};
// @lc code=end
