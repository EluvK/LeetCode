/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
class Solution {
public:
    int splitNum(int num) {
        auto s = std::to_string(num);
        sort(s.begin(), s.end());
        int n1 = 0, n2 = 0;
        bool flag = true;
        for (auto c : s) {
            if (flag)
                n1 = n1 * 10 + c - '0';
            else
                n2 = n2 * 10 + c - '0';
            flag = !flag;
        }
        return n1 + n2;
    }
};
// @lc code=end
