/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start
class Solution {
public:
    long long repairCars(vector<int> & ranks, int cars) {
        long long l = 0;
        long long r = (long long)1 * ranks[0] * cars * cars;
        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            long long sum = 0;
            for (auto r : ranks) {
                sum += (long long)(sqrt(mid / r));
                if (sum >= cars)
                    break;
            }
            (sum >= cars ? r : l) = mid;
        }
        return r;
    }
};
// @lc code=end
