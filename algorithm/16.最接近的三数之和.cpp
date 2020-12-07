/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

class Solution {

public:
    int threeSumClosest(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        int dif = INT_MAX, ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            if (j >= nums.size() || j >= k)
                break;
            while (j < k) {
                cout << i << " " << j << " " << k << endl;
                int temp = nums[i] + nums[j] + nums[k];
                if (temp > target) {
                    if (temp - target < dif) {
                        ans = temp;
                        dif = temp - target;
                    }
                    --k;
                } else if (temp < target) {
                    if (target - temp < dif) {
                        ans = temp;
                        dif = target - temp;
                    }
                    ++j;
                } else
                    return temp;
            }
        }
        return ans;
    }
};

// @lc code=end
