/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int> & nums) {
        int len = 0, st = 0, sum = 0;
        for (int ed = 0; ed < nums.size(); ++ed) {
            sum += nums[ed];
            while (sum >= s) {
                len = len == 0 ? ed - st + 1 : min(len, ed - st + 1);
                sum -= nums[st++];
            }
        }
        return len;
    }
};
// @lc code=end
