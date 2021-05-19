/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> s;
    NumArray(vector<int> & nums) {
        int m = nums.size();
        if (m) {
            s.resize(m);
        }
        for (auto index = 0; index < m; ++index) {
            s[index] += nums[index];
            if (index) {
                s[index] += s[index - 1];
            }
        }
    }

    int sumRange(int left, int right) { return s[right] - (left ? s[left - 1] : 0); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
