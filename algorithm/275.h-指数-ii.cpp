/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int> & citations) {
        int total = citations.size(), res = 0;
        for (int l = 0, r = total - 1; l <= r;) {
            int mid = l + (r - l) / 2;
            if (citations[mid] >= total - mid) {
                res = total - mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
// @lc code=end
