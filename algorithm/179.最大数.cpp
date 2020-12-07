/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int> & nums) {
        sort(nums.begin(), nums.end(), [](int & a, int & b) -> bool {
            string sa = to_string(a) + to_string(b), sb = to_string(b) + to_string(a);
            return sa > sb;
        });
        string ans{};
        if (!nums[0])
            return "0";
        for (auto c : nums) {
            ans += to_string(c);
        }
        return ans;
    }
};
// @lc code=end
