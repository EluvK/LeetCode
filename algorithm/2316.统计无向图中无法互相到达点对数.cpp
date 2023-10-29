/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
class Solution {
public:
    long long countPairs(int n, vector<vector<int>> & edges) {
        vector<vector<int>> g(n);
        for (auto & e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        queue<int> q;
        vector<int> gc;
        for (int i = 0; i < n; ++i) {
            if (vis[i])
                continue;
            q.push(i);
            vis[i] = true;
            int cnt = 0;
            while (!q.empty()) {
                int f = q.front();
                q.pop();
                cnt++;
                for (auto next : g[f]) {
                    if (vis[next])
                        continue;
                    q.push(next);
                    vis[next] = true;
                }
            }
            gc.push_back(cnt);
        }
        long long ans = 0;
        for (int i = 1; i < gc.size(); ++i) {
            ans += (long long)gc[i] * gc[i - 1];
            gc[i] += gc[i - 1];
        }
        return ans;
    }
};
// @lc code=end
