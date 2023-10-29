/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int> & satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int ans = 0, sum = 0;
        for (int i = 0; i < satisfaction.size(); ++i) {
            sum += satisfaction[i];
            if (sum < 0)
                break;
            ans += sum;
        }
        return ans;
    }
};
// @lc code=end
