/*
 * @lc app=leetcode.cn id=1761 lang=cpp
 *
 * [1761] 一个图中连通三元组的最小度数
 */

// @lc code=start
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges)
    {
        vector<pair<int, int>> d;
        for (int index = 0; index < n; ++index) {
            d.push_back(make_pair(index, 0));
        }
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for (auto edge : edges) {
            auto from = edge[0] - 1;
            auto to = edge[1] - 1;
            g[from][to] = g[to][from] = true;
            d[from].second += 1;
            d[to].second += 1;
        }
        sort(d.begin(), d.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
        int res = INT_MAX;
        for (auto i = 0; i < n && d[i].second >= 2; ++i) {
            for (auto j = i + 1; j < n && d[j].second >= 2; ++j) {
                for (auto k = j + 1; k < n && d[k].second >= 2; ++k) {
                    if (g[d[i].first][d[j].first] && g[d[j].first][d[k].first] && g[d[i].first][d[k].first]) {
                        res = min(res, d[i].second + d[j].second + d[k].second - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

// @lc code=end

