/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
class Solution {
public:
    int eliminateMaximum(vector<int> & dist, vector<int> & speed) {
        vector<int> cnt(1e5 + 5, 0);
        for (int i = 0; i < dist.size(); ++i) {
            cnt[(dist[i] + speed[i] - 1) / speed[i]]++;
        }
        for (int i = 1; i < cnt.size(); ++i)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] > i)
                return i;
        }
        return dist.size();
    }
};
// @lc code=end
