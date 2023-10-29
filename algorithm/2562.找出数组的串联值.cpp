/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
class Solution {
public:
    long long findTheArrayConcVal(vector<int> & nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int x = nums[i];
            int y = nums[j];
            while (y) {
                x *= 10;
                y /= 10;
            }
            ans += x + nums[j];
            i++;
            j--;
        }
        if (i == j) {
            ans += nums[j];
        }
        return ans;
    }
};
// @lc code=end
