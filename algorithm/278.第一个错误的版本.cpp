/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // bool isBadVersion(int n){return false};
    int firstBadVersion(int n) {
        int l = 1, h = n, mid = l + (h - l) / 2;
        while (l < h) {
            if (isBadVersion(mid))
                h = mid;
            else
                l = mid + 1;
            mid = l + (h - l) / 2;
        }
        return l;
    }
};
// @lc code=end
