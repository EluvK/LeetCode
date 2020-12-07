/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int> & nums) {
        vector<int> res;
        int x = 0, y = 0, cx = 0, cy = 0, count = 0;
        for (auto num : nums) {
            if ((cx == 0 || num == x) && num != y) {
                ++cx, x = num;
            } else if (cy == 0 || num == y) {
                ++cy, y = num;
            } else {
                --cx, --cy;
            }
        }
        for (auto num : nums) {
            if (x == num) {
                ++count;
            }
        }
        if (count > nums.size() / 3) {
            res.push_back(x);
        }
        count = 0;
        for (auto num : nums) {
            if (y == num) {
                ++count;
            }
        }
        if (count > nums.size() / 3 && x != y) {
            res.push_back(y);
        }
        return res;
    }
};
// @lc code=end
