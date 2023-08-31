/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
class Solution {
public:
    int numFactoredBinaryTrees(vector<int> & arr) {
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        for (auto n : arr) {
            dp[n] = 1;
            for (auto & [k, v] : dp) {
                if (n % k == 0 && dp.count(n / k)) {
                    dp[n] = (dp[n] + (dp[k] * dp[n / k] % mod)) % mod;
                }
            }
        }
        long long s = 0;
        for (auto & [k, v] : dp) {
            s = (s + v) % mod;
        }
        return (int)s;
    }
};
// @lc code=end
