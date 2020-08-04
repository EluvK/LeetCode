/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    set<vector<int>> ans;
    vector<int> tmp;
    void solve(vector<int> & nums, int n) {
        tmp.clear();
        int index = 0;
        while (n) {
            if (n & 1)
                tmp.push_back(nums[index]);
            index++;
            n = n >> 1;
        }
        sort(tmp.begin(), tmp.end());
        ans.insert(tmp);
    }

    vector<vector<int>> subsetsWithDup(vector<int> & nums) {
        for (int i = 0; i < (1 << nums.size()); ++i)
            solve(nums, i);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
// @lc code=end
