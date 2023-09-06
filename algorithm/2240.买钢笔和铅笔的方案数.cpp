/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        std::vector<int> index(total / cost1 + 1);
        std::iota(index.begin(), index.end(), 0);
        return std::accumulate(index.begin(), index.end(), (long long)0, [&](long long r, int num) {
            r += (total - cost1 * num) / cost2 + 1;
            return r;
        });
    }
};
// @lc code=end
