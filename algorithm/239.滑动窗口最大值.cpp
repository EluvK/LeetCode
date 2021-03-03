/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> & nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int index = 0; index < nums.size(); index++) {
            if (!dq.empty() && dq.front() == index - k)
                dq.pop_front();
            while (!dq.empty() && nums[index] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(index);
            if (index >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
// @lc code=end
