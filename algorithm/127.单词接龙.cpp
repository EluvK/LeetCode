/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> & wordList) {
        int len = wordList.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < len; i++) {
            mp[wordList[i]] = -1;
        }
        if (mp[endWord] != -1)
            return 0;
        queue<string> q;
        while (!q.empty())
            q.pop();
        q.push(beginWord);
        mp[beginWord] = 0;
        while (!q.empty()) {
            string f = q.front();
            q.pop();
            for (int i = 0; i < f.size(); i++) {
                string temp = f;
                int fi = mp[f];
                for (int j = 0; j < 26; j++) {
                    temp[i] = j + 'a';
                    if (mp[temp] == -1) {
                        mp[temp] = fi + 1;
                        if (temp == endWord)
                            return fi + 2;
                        q.push(temp);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
