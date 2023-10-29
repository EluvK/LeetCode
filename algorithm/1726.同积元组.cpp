/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int> & nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cnt[nums[i] * nums[j]]++;
            }
        }
        for (auto & [k, v] : cnt) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};

// @lc code=end
