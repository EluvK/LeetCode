/*
 * @lc app=leetcode.cn id=2731 lang=cpp
 *
 * [2731] 移动机器人
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;

public:
    int sumDistance(vector<int> & nums, string s, int d) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            a[i] = (long long)nums[i] + d * ((s[i] & 2) - 1);  // L=-1, R=1
        sort(a.begin(), a.end());

        long long ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + i * a[i] - sum) % MOD;
            sum += a[i];
        }
        return ans;
    }
};
// @lc code=end
