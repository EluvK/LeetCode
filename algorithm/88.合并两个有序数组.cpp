/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) {
        int i = m - 1, j = n - 1;
        int index = nums1.size() - 1;
        if (!n)
            return;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[index] = nums1[i];
                i--;
            } else {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        while (i >= 0) {
            nums1[index--] = nums1[i--];
        };
        while (j >= 0) {
            nums1[index--] = nums2[j--];
        };
        return;
    }
};
// @lc code=end
