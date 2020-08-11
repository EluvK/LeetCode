/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> & nums) {
        if (nums.empty())
            return 0;
        set<int> st{nums.begin(), nums.end()};
        int res = 1;
        for (auto n : st) {
            if (st.count(n - 1))
                continue;
            int ans = 1, tmp = n;
            while (st.count(++n))
                ans++;
            res = max(ans, res);
        }
        return res;
    }
};
// @lc code=end
