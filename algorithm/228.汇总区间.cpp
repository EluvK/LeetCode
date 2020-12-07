/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int> & nums) {
        vector<string> ans;
        if (nums.empty())
            return ans;
        if (nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int st = nums[0], ed, tmp = st;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == tmp + 1) {
                tmp++;
                continue;
            } else {
                string res;
                if (st == tmp)
                    res = to_string(st);
                else
                    res = to_string(st) + "->" + to_string(tmp);
                ans.push_back(res);
                tmp = st = nums[i];
            }
        }
        string res;
        if (st == tmp)
            res = to_string(st);
        else
            res = to_string(st) + "->" + to_string(tmp);
        ans.push_back(res);
        return ans;
    }
};
// @lc code=end
