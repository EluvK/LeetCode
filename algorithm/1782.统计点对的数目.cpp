/*
 * @lc app=leetcode.cn id=1782 lang=cpp
 *
 * [1782] 统计点对的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>> & edges, vector<int> & queries) {
        vector<int> d(n + 1, 0);
        map<pair<int, int>, int> mp;
        // unordered_map<int, int> cnt_e;
        for (auto const & e : edges) {
            d[e[0]]++;
            d[e[1]]++;

            mp[{std::min(e[0], e[1]), std::max(e[0], e[1])}] += 1;
            // cnt_e[(std::min(e[0], e[1]) << 16) | std::max(e[0], e[1])]++;
        }
        unordered_map<int, int> cnt_d;
        for (int i = 1; i <= n; ++i) {
            cnt_d[d[i]]++;
        }
        int max_d = *max_element(d.begin() + 1, d.end());
        vector<int> cnt(2 * edges.size() + 2, 0);

        for (auto [d1, c1] : cnt_d) {
            for (auto [d2, c2] : cnt_d) {
                if (d1 < d2) {
                    cnt[d1 + d2] += c1 * c2;
                } else if (d1 == d2) {
                    cnt[d1 + d2] += c1 * (c1 - 1) / 2;
                }
            }
        }

        for (auto [p, c] : mp) {
            int s = d[p.first] + d[p.second];
            cnt[s]--;
            cnt[s - c]++;
        }

        for (int i = cnt.size() - 2; i >= 0; i--) {
            cnt[i] += cnt[i + 1];
        }
        vector<int> res;
        res.reserve(queries.size());
        for (auto q : queries) {
            res.emplace_back(cnt[q + 1]);
        }

        return res;
    }
};
// @lc code=end
