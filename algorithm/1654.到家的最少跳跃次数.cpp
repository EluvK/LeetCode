/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
class Solution {
public:
    int maxPos{0};
    bool valid_pos(int pos) { return pos >= 0 && pos <= maxPos; }
    int minimumJumps(vector<int> & forbidden, int a, int b, int x) {
        if (x == 0)
            return 0;
        int max_f = *std::max_element(forbidden.begin(), forbidden.end());
        maxPos = a >= b ? std::max(x + b, max_f) : std::max(x, max_f + a + b);
        // std::cout << "maxPos:" << maxPos << endl;
        vector<int> vis(maxPos + 1, false);
        vector<int> rev_vis(maxPos + 1, false);
        vis[0] = true;
        rev_vis[0] = true;
        for (auto pos : forbidden) {
            vis[pos] = true;
            rev_vis[pos] = true;
        }
        std::queue<std::tuple<int, int, bool>> q;
        q.push(std::make_tuple(0, 0, false));
        while (!q.empty() && !vis[x]) {
            std::vector<std::tuple<int, int, bool>> next;
            while (!q.empty()) {
                auto f = q.front();
                q.pop();
                int next_pos = std::get<0>(f) + a;
                if (next_pos == x) {
                    return std::get<1>(f) + 1;
                }
                // std::cout << "next_pos:" << next_pos << std::endl;
                if (valid_pos(next_pos) && !vis[next_pos]) {
                    vis[next_pos] = true;
                    next.push_back(std::make_tuple(next_pos, std::get<1>(f) + 1, false));
                }
                if (!std::get<2>(f)) {
                    int next_rev_pos = std::get<0>(f) - b;
                    if (next_rev_pos == x) {
                        return std::get<1>(f) + 1;
                    }
                    // std::cout << "next_rev_pos:" << next_rev_pos << std::endl;
                    if (valid_pos(next_rev_pos) && !rev_vis[next_rev_pos]) {
                        rev_vis[next_rev_pos] = true;
                        next.push_back(std::make_tuple(next_rev_pos, std::get<1>(f) + 1, true));
                    }
                }
            }
            for (auto & p : next) {
                // std::cout << std::get<0>(p) << " ";
                q.push(p);
            }
            // std::cout << endl;
        }
        return -1;
    }
};
// @lc code=end
