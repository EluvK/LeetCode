/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner() {
        index = -1;
        st.push(make_pair(-1, INT_MAX));
    }

    int next(int price) {
        index++;
        while (price >= st.top().second)
            st.pop();
        int ret = index - st.top().first;
        st.push(make_pair(index, price));
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
