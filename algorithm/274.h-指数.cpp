/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int> & citations) {
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size(); ++i) {
            if (citations[i] < i + 1)
                break;
        }
        return i;
    }
};

// @lc code=end
