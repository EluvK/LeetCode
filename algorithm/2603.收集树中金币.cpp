/*
 * @lc app=leetcode.cn id=2603 lang=cpp
 *
 * [2603] 收集树中金币
 */

// @lc code=start
class Solution {
public:
    int collectTheCoins(vector<int> & coins, vector<vector<int>> & edges) {
        int n = coins.size();
        vector<vector<int>> graph(n);
        vector<int> d(n);
        for (auto const & edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            d[x]++;
            d[y]++;
        }

        int rest = n;

        {
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (d[i] == 1 && !coins[i]) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int f = q.front();
                q.pop();
                d[f]--;
                rest--;
                for (auto h : graph[f]) {
                    d[h]--;
                    if (d[h] == 1 && !coins[h]) {
                        q.push(h);
                    }
                }
            }
        }

        for (int _ = 0; _ < 2; ++_) {
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (d[i] == 1) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int f = q.front();
                q.pop();
                d[f]--;
                rest--;
                for (auto h : graph[f]) {
                    d[h]--;
                }
            }
        }

        return rest == 0 ? 0 : (rest - 1) * 2;
    }
};
// @lc code=end
