/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> & prerequisites) {
        vector<vector<bool>> preList(numCourses, vector<bool>(numCourses, false));
        // preList[a][b] = true means learning a then learning b.
        vector<int> relay(numCourses, 0);
        vector<bool> vis(numCourses, false);
        for (auto v : prerequisites) {
            preList[v[1]][v[0]] = true;
            relay[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!relay[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            res.push_back(f);
            for (int i = 0; i < numCourses; ++i) {
                if (preList[f][i]) {
                    if (--relay[i] == 0) {
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
// @lc code=end
