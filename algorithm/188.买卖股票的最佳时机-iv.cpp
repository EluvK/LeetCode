/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfitGreed(vector<int> & prices) {
        if (prices.empty())
            return 0;
        int ans = 0, last = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > last)
                ans += (prices[i] - last);
            last = prices[i];
        }
        return ans;
    }
    int maxProfit(int k, vector<int> & prices) {
        if (k < 1)
            return 0;
        if (k >= prices.size() / 2)
            return maxProfitGreed(prices);
        vector<int> buyv(k, INT_MIN), sellv(k, 0);
        for (auto p : prices) {
            for (int i = 0; i < k; ++i) {
                buyv[i] = max(buyv[i], i == 0 ? -p : sellv[i - 1] - p);
                sellv[i] = max(sellv[i], buyv[i] + p);
            }
        }
        return sellv[k - 1];
    }
};
// @lc code=end
