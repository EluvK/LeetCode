/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        while (--k) {
            next_permutation(nums.begin(), nums.end());
        }
        string ans{};
        for (auto c : nums) {
            ans = ans + to_string(c);
        }
        return ans;
    }
};
// @lc code=end
