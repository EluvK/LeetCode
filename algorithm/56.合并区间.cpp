/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) { return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1]; });
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size()) {
            int st = intervals[i][0], ed = intervals[i][1];
            while (++i < intervals.size()) {
                if (intervals[i][0] <= ed) {
                    ed = max(intervals[i][1], ed);
                } else {
                    break;
                }
            }
            ans.push_back({st, ed});
        }
        return ans;
    }
};

// @lc code=end
