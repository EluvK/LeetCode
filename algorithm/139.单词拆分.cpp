/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string> & wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
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
};
// @lc code=end
