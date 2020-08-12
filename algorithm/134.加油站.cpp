/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int> & gas, vector<int> & cost) {
        int run = 0, rest = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            run += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            if (run < 0) {
                run = 0;
                start = i + 1;
            }
        }
        return rest >= 0 ? start : -1;
    }
};
// @lc code=end
