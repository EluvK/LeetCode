/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> & prerequisites, vector<vector<int>> & queries) {
        bool pre[numCourses][numCourses];
        memset(pre, 0, sizeof(bool) * numCourses * numCourses);
        for (auto pr : prerequisites) {
            pre[pr[0]][pr[1]] = true;
        }
        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                for (int k = 0; k < numCourses; ++k) {
                    if (pre[j][i] && pre[i][k]) {
                        pre[j][k] = true;
                    }
                }
            }
        }
        vector<bool> ans;
        for (auto q : queries) {
            if (pre[q[0]][q[1]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
// @lc code=end
