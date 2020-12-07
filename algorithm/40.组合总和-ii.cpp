/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void solve(set<vector<int>> & ans, vector<int> & res, vector<int> & candidates, int sum, int index) {
        if (sum == 0) {
            ans.insert(res);
            return;
        }
        if (sum < 0 || index >= candidates.size())
            return;
        for (int i = index; i < candidates.size(); ++i) {
            res.push_back(candidates[i]);
            solve(ans, res, candidates, sum - candidates[i], i + 1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {
        set<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(ans, res, candidates, target, 0);
        vector<vector<int>> vans(ans.begin(), ans.end());
        return vans;
    }
};
// @lc code=end
