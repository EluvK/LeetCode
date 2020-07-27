/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ans;
        if (len < 4)
            return ans;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i && nums[i] == nums[i - 1])
                continue;
            int t = target - nums[i];
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[l]<<" "<<nums[r]<<endl;
                    int sum = nums[j] + nums[l] + nums[r];
                    if (sum == t) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < len && nums[l] == nums[l - 1])
                            l++;
                        while (r > 0 && nums[r] == nums[r + 1])
                            r--;
                    } else if (sum < t) {
                        l++;
                        while (l < len && nums[l] == nums[l - 1])
                            l++;
                    } else {
                        r--;
                        while (r > 0 && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end
