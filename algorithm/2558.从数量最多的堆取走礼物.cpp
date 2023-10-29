/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int> & gifts, int k) {
        priority_queue<int> pq;
        for (auto g : gifts)
            pq.push(g);
        while (k--) {
            auto f = pq.top();
            pq.pop();
            pq.push(sqrt(f));
        }
        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
