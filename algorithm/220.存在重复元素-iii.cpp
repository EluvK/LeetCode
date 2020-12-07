/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> & nums, int k, int t) {
        set<long> st;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = st.lower_bound((long)nums[i] - t);
            if (it != st.end() && *it <= (long)nums[i] + t)
                return true;
            st.insert(nums[i]);
            if (st.size() == k + 1)
                st.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end
