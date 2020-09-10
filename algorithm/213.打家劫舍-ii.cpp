/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int work(vector<int> & nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len < 3)
            return *max_element(nums.begin(), nums.end());
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < len; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[len - 1];
    }

    int rob(vector<int> & nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> t1(nums.size() - 1), t2(nums.size() - 1);
        for (int i = 1; i < nums.size(); ++i)
            t1[i - 1] = nums[i];
        for (int i = 1; i < nums.size(); ++i)
            t2[i - 1] = nums[i - 1];
        return max(work(t1), work(t2));
    }
};

// @lc code=end
