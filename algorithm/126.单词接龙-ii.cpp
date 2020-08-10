/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool check_diff(string & a, string & b) {
        int len = a.size();
        bool once = false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                if (!once)
                    once = true;
                else
                    return false;
            }
        }
        return true;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> & wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return {};
        map<string, set<string>> mp;
        set<string> vist;

        for (int i = 0; i < wordList.size(); i++) {
            if (check_diff(beginWord, wordList[i])) {
                mp[beginWord].insert(wordList[i]);
            }
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (check_diff(wordList[i], wordList[j])) {
                    mp[wordList[i]].insert(wordList[j]);
                    mp[wordList[j]].insert(wordList[i]);
                }
            }
        }

        vector<vector<string>> res;
        queue<vector<string>> q;
        unordered_map<string, int> dis;

        for (int i = 0; i < wordList.size(); i++)
            dis[wordList[i]] = INT_MAX - 1;
        dis[beginWord] = 0;
        q.push(vector<string>{beginWord});
        while (!q.empty()) {
            vector<string> cur = q.front();
            q.pop();
            string last = cur.back();
            if (last == endWord) {
                res.push_back(cur);
            } else {
                for (auto str : mp[last]) {
                    if (dis[last] + 1 <= dis[str]) {
                        dis[str] = dis[last] + 1;
                        vector<string> newq(cur);
                        newq.push_back(str);
                        q.push(newq);
                    }
                }
            }
        }

        return res;
    }
};

// @lc code=end
