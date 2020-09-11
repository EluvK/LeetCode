/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> & buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;

        for (auto & b : buildings) {
            all.insert(make_pair(b[0], -b[2]));
            all.insert(make_pair(b[1], b[2]));
        }

        multiset<int> heights({0});
        vector<int> last = {0, 0};

        for (auto & p : all) {
            if (p.second < 0)
                heights.insert(-p.second);
            else
                heights.erase(heights.find(p.second));

            auto maxH = *heights.rbegin();

            if (last[1] != maxH) {
                last[0] = p.first;
                last[1] = maxH;
                res.push_back(last);
            }
        }
        return res;
    }
};
// @lc code=end
