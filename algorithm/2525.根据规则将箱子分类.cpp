/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long maxd = max(length, max(width, height)), vol = 1L * length * width * height;
        bool isBulky = maxd >= 10000 || vol >= 1000000000, isHeavy = mass >= 100;
        if (isBulky && isHeavy) {
            return "Both";
        } else if (isBulky) {
            return "Bulky";
        } else if (isHeavy) {
            return "Heavy";
        }
        return "Neither";
    }
};
// @lc code=end
