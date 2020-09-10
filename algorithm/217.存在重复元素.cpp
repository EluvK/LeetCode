/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        unordered_map<int, bool> mp;
        for (auto n : nums) {
            if (mp[n])
                return true;
            else
                mp[n] = true;
        }
        return false;
    }
};
// @lc code=end
