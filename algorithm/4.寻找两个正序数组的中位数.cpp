/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 > len2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = len1 * 2;
        int c1, c2, mx1, mx2, mn1, mn2;
        while (low <= high) {
            c1 = (low + high) / 2;
            c2 = len1 + len2 - c1;

            mx1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            mn1 = (c1 == 2 * len1) ? INT_MAX : nums1[c1 / 2];
            mx2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            mn2 = (c2 == 2 * len2) ? INT_MAX : nums2[c2 / 2];

            if (mx1 > mn2)
                high = c1 - 1;
            else if (mx2 > mn1)
                low = c1 + 1;
            else
                break;
        }
        return (max(mx1, mx2) + min(mn1, mn2)) / 2.0;
    }
};

// @lc code=end
