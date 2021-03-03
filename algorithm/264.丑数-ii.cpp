/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        vector<int> arr(1, 1);
        int ii = 0, ji = 0, ki = 0;
        while (--n) {
            int i = 2 * arr[ii], j = 3 * arr[ji], k = 5 * arr[ki];
            int res = std::min(std::min(i, j), k);
            if (i == res)
                ii++;
            if (j == res)
                ji++;
            if (k == res)
                ki++;
            arr.push_back(res);
        }
        return arr.back();
    }
};
// @lc code=end
