/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
class Solution {
public:
    int minCapability(vector<int> & nums, int k) {
        auto [m, n] = minmax_element(nums.begin(), nums.end());
        int l = *m, r = *n;
        auto d = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < nums.size() && cnt < k;) {
                if (nums[i] <= x) {
                    cnt += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            return cnt == k;
        };
        while (l < r) {
            int m = (l + r) / 2;
            if (d(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
// @lc code=end
