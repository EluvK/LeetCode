/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp1(n, vector<int>(n));  //[i, j]是否是回文串
        vector<int> dp2(n, n);                       //[0, i]的最少分割次数
        dp2[0] = 0;
        for (int j = 0; j < n; j++) {
            dp1[j][j] = 1;
            for (int i = j; i >= 0; i--) {
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        dp1[i][j] = 1;
                    else
                        dp1[i][j] = dp1[i + 1][j - 1];
                }
                if (dp1[i][j]) {
                    if (i >= 1)
                        dp2[j] = min(dp2[j], dp2[i - 1] + 1);
                    else
                        dp2[j] = 0;
                }
            }
        }
        return dp2[n - 1];
    }
};
// @lc code=end
