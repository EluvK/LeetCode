/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    vector<string> split_words(string const & input) {
        vector<string> res;
        string tmp;
        for (auto c : input) {
            if (c == ' ') {
                res.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(c);
        }
        if (!tmp.empty())
            res.push_back(tmp);
        return res;
    }
    bool wordPattern(string pattern, string s) {
        auto words = split_words(s);
        if (words.size() != pattern.size())
            return false;
        std::map<int, std::string> dict;
        std::map<std::string, int> rdict;
        for (auto index = 0; index < words.size(); ++index) {
            if (dict.find(pattern[index] - 'a') != dict.end() && dict[pattern[index] - 'a'] != words[index])
                return false;
            dict[pattern[index] - 'a'] = words[index];
            if (rdict.find(words[index]) != rdict.end() && rdict[words[index]] != pattern[index] - 'a')
                return false;
            rdict[words[index]] = pattern[index] - 'a';
        }
        return true;
    }
};
// @lc code=end
