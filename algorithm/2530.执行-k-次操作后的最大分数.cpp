/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int> & nums, int k) {
        std::priority_queue<int> pq;
        long long res = 0;
        for (auto n : nums) {
            pq.emplace(n);
        }
        for (int i = 0; i < k; ++i) {
            auto n = pq.top();
            pq.pop();
            res += n;
            pq.emplace((n + 2) / 3);
        }
        return res;
    }
};
// @lc code=end
