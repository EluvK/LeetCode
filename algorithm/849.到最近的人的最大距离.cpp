/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int> & seats) {
        auto sz = seats.size();
        std::vector<int> l(sz, 0);
        std::vector<int> r(sz, 0);
        int fl = 0;
        int fr = 0;
        for (int i = 0; i < sz; ++i) {
            if (seats[i] == 1) {
                fl = i;
                break;
            }
        }
        for (int i = sz - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                fr = i;
                break;
            }
        }
        for (int i = 0; i < sz; ++i) {
            if (seats[i] == 1) {
                fl = i;
            }
            l[i] = std::abs(fl - i);
        }
        for (int i = sz - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                fr = i;
            }
            r[i] = std::abs(fr - i);
        }
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            res = std::max(res, std::min(l[i], r[i]));
        }
        return res;
    }
};
// @lc code=end
