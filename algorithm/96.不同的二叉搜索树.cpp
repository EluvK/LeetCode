/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> arr(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                tmp += arr[j] * arr[i - j - 1];
            }
            arr[i] = tmp;
        }
        return arr[n];
    }
};
// @lc code=end
