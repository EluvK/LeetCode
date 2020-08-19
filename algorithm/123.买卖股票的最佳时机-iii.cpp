/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int buy_one = INT_MIN, sell_one = 0;
        int buy_two = INT_MIN, sell_two = 0;
        for (auto p : prices) {
            buy_one = max(buy_one, -p);
            sell_one = max(sell_one, buy_one + p);
            buy_two = max(buy_two, sell_one - p);
            sell_two = max(sell_two, buy_two + p);
        }
        return sell_two;
    }
};

// @lc code=end
