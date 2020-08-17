/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            n--;
            char c = n % 26 + 'A';
            res.push_back(c);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
