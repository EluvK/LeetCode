/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> & prerequisites) {
        vector<vector<bool>> preList(numCourses, vector<bool>(numCourses, false));
        // preList[a][b] = true means learning a then learning b.
        vector<int> relay(numCourses, 0);
        vector<bool> vis(numCourses, false);
        for (auto v : prerequisites) {
            preList[v[0]][v[1]] = true;
            relay[v[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!relay[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int i = 0; i < numCourses; ++i) {
                if (preList[f][i]) {
                    if (--relay[i] == 0) {
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
        }
        for (auto b : vis) {
            if (!b)
                return false;
        }
        return true;
    }
};
// @lc code=end
