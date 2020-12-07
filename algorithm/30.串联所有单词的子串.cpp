/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> & words) {
        vector<int> ans;
        map<string, int> mp;
        if (!s.size() || !words.size())
            return ans;
        int num = words.size(), step = words[0].size();
        for (auto c : words)
            mp[c]++;
        int len = num * step;
        if (len > s.size())
            return ans;
        for (int i = 0; i <= s.size() - len; ++i) {
            string tmp = s.substr(i, len);
            map<string, int> cnt = mp;
            bool flag = true;
            for (int j = 0; j < tmp.size(); j = j + step) {
                string wd = tmp.substr(j, step);
                if (cnt[wd]) {
                    cnt[wd]--;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(i);
        }
        return ans;
    }
};

// @lc code=end
