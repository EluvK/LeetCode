/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    vector<string> tmp;
    unordered_set<string> wordset;
    bool wordBreakable(string s, vector<string> & wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        wordset = unordered_set<string>(wordDict.begin(), wordDict.end());
        int maxwordsize = 0;
        for (auto word : wordDict) {
            maxwordsize = std::max(maxwordsize, static_cast<int>(word.size()));
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = std::max(i - maxwordsize, 0); j < i; ++j) {
                if (dp[j] && wordset.find(s.substr(j, i - j)) != wordset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
    void dfs(string & s, int l, int r) {
        if (l > r) {
            string res;
            for (int i = 0; i < tmp.size(); ++i) {
                res = res + tmp[i];
                if (i != tmp.size() - 1)
                    res = res + " ";
            }
            ans.push_back(res);
            return;
        }
        for (int i = 1; i <= r - l + 1; ++i) {
            string sub_str = s.substr(l, i);
            if (wordset.find(sub_str) != wordset.end()) {
                tmp.push_back(sub_str);
                dfs(s, l + i, r);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string> & wordDict) {
        if (!wordBreakable(s, wordDict))
            return ans;
        dfs(s, 0, s.size() - 1);
        return ans;
    }
};
// @lc code=end
