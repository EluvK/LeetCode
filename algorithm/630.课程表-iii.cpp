/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>> & courses) {
        sort(courses.begin(), courses.end(), [](vector<int> & a, vector<int> & b) { return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0]; });
        priority_queue<int> q;
        int cnt = 0, cur = 0;
        for (auto & c : courses) {
            if (c[1] < c[0])
                continue;
            if (c[1] - c[0] >= cur) {
                cnt++;
                cur += c[0];
                q.push(c[0]);
            } else {
                int v = q.top();
                q.pop();
                if (v > c[0]) {
                    cur -= (v - c[0]);
                    v = c[0];
                }
                q.push(v);
            }
        }
        return cnt;
    }
};
// @lc code=end
