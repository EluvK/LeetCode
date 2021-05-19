/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    /*
            1
           / \
          2   3
         / \
        4   5


            9
           / \
          8   1
         / \
        3   5

    */

    vector<int> tree;
    int n;
    NumArray(vector<int> & nums) {
        n = nums.size();
        tree.resize(n << 1);
        for (int i = n, j = 0; j < nums.size(); ++i, ++j) {
            tree[i] = nums[j];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
    }

    void update(int index, int val) {
        auto gap = val - tree[index + n];
        tree[index + n] = val;
        auto i = (index + n) >> 1;
        while (i) {
            tree[i] += gap;
            i >>= 1;
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) {
            if (left & 1) {
                sum += tree[left++];
            }
            if (!(right & 1)) {
                sum += tree[right--];
            }
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
