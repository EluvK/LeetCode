/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
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
        ans.push_back(tmp);
    }
    vector<vector<int>> subsets(vector<int> & nums) {
        for (int i = 0; i < (1 << nums.size()); ++i)
            solve(nums, i);
        return ans;
    }
};
// @lc code=end
