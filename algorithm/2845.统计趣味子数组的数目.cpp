/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long countInterestingSubarrays(vector<int> & nums, int modulo, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        map<int, int> count;
        count[0] = 1;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (nums[i] % modulo == k);
            result += count[(prefix[i + 1] + modulo - k) % modulo];
            count[prefix[i + 1] % modulo]++;
        }
        return result;
    }
};
// @lc code=end
