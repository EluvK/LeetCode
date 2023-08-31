/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

// @lc code=start
class Solution {
public:
    bool canChange(string start, string target) {
        int sum_start_r = 0, sum_target_l = 0;
        for (auto index = 0; index < start.size(); ++index) {
            char start_char = start[index];
            char target_char = target[index];
            if (target_char == 'L') {
                if (sum_start_r != 0)
                    return false;
                sum_target_l++;
            }
            if (start_char == 'R') {
                if (sum_target_l != 0)
                    return false;
                sum_start_r++;
            }
            if (target_char == 'R') {
                if (sum_start_r == 0)
                    return false;
                sum_start_r--;
            }
            if (start_char == 'L') {
                if (sum_target_l == 0)
                    return false;
                sum_target_l--;
            }
        }
        return sum_start_r == sum_target_l && sum_start_r == 0;
    }
};
// @lc code=end
