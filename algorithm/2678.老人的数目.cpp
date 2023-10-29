/*
 * @lc app=leetcode.cn id=2678 lang=cpp
 *
 * [2678] 老人的数目
 */

// @lc code=start
class Solution {
public:
    int countSeniors(vector<string> & details) {
        int ans = 0;
        for (auto & s : details)
            ans += (s[11] - '0') * 10 + s[12] - '0' > 60;
        return ans;
    }
};
// @lc code=end
