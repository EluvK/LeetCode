/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
using namespace std;
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int target, num;
    void solve(int st, int sum, int tn) {
        if (sum > target)
            return;
        if (tn == num && sum == target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = st; i <= 9 && sum + i <= target; ++i) {
            tmp.push_back(i);
            // std::cout << "push " << i << std::endl;
            solve(i + 1, sum + i, tn + 1);
            tmp.pop_back();
            // std::cout << "pop " << i << std::endl;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n;
        num = k;
        solve(1, 0, 0);
        return ans;
    }
};
// @lc code=end
