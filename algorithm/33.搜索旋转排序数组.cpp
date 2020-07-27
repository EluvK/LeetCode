/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int search(vector<int> & nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }
        // cout<<l<<endl;
        // 0-l-1,l-len-1;
        int ll = 0, lr = l - 1;
        while (ll <= lr) {
            int mid = ll + (lr - ll) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                lr = mid - 1;
            else
                ll = mid + 1;
        }
        int rl = l, rr = len - 1;
        while (rl <= rr) {
            int mid = rl + (rr - rl) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                rr = mid - 1;
            else
                rl = mid + 1;
        }
        return -1;
    }
};

// @lc code=end
