/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> & nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.insert(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end
