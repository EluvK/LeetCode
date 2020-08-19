/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int buy = INT_MIN, sell = 0;
        for (auto p : prices) {
            buy = max(buy, -p);
            sell = max(sell, buy + p);
        }
        return sell;
    }
};

// @lc code=end
