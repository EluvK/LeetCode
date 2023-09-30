/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 全部开花的最早一天
 */

// @lc code=start
class Solution {
public:
    // for i,j with g[i]>g[j]
    // p[i] + p[j] + g[i]
    using pii = pair<int, int>;
    int earliestFullBloom(vector<int> & plantTime, vector<int> & growTime) {
        vector<pii> f;
        for (int i = 0; i < plantTime.size(); ++i) {
            f.push_back(make_pair(plantTime[i], growTime[i]));
        }
        sort(f.begin(), f.end(), [](pii & a, pii & b) { return a.second != b.second ? a.second > b.second : a.first > b.first });
        int cur_t = 0;
        int bloom_t = 0;
        for (auto & [p, g] : f) {
            cur_t += p;
            bloom_t = max(bloom_t, cur_t + g + 1);
        }
        return bloom_t - 1;
    }
};
// @lc code=end
