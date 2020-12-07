/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    pair<int, int> getK(pair<int, int> const & a, pair<int, int> const & b) {
        int dy = b.second - a.second;
        int dx = b.first - a.first;
        if (!dx && !dy)
            return make_pair(0, 0);
        if (!dx)
            return make_pair(1997, 0);
        if (!dy)
            return make_pair(0, 1997);
        int g = gcd(dy, dx);
        return make_pair(dy / g, dx / g);
    }
    int maxPoints(vector<vector<int>> & points) {
        if (points.size() < 3)
            return points.size();
        int sz = points.size();
        int cnt = sz * 2;
        int res = 0;

        for (int i = 0; i < cnt; ++i) {
            int randi = rand() % sz, randj = rand() % sz;
            if (points[randi] == points[randj]) {
                for (randj = 0; randj < sz; ++randj) {
                    if (points[randi] != points[randj])
                        break;
                }
                if (randj == sz)
                    return sz;
            }
            pair<int, int> tk = getK(make_pair(points[randi][0], points[randi][1]), make_pair(points[randj][0], points[randj][1]));
            int ans = 2;
            for (int j = 0; j < sz; ++j) {
                if (j == randi || j == randj)
                    continue;
                auto resK = getK(make_pair(points[randi][0], points[randi][1]), make_pair(points[j][0], points[j][1]));
                if (resK == make_pair(0, 0) || resK == tk) {
                    ans++;
                }
            }
            res = max(ans, res);
        }
        return res;
    }
};

// @lc code=end
