/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            if (mp[target - t] != 0) {
                res.push_back(mp[target - t] - 1);
                res.push_back(i);
                return res;
            }
            mp[t] = i + 1;
        }
        return res;
    }
};

// @lc code=end
