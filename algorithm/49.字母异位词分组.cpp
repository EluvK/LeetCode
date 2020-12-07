/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> & strs) {
        int prime_num[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        map<uint64_t, vector<string>> mp;
        for (auto s : strs) {
            uint64_t res = 1;
            for (auto c : s) {
                res *= prime_num[c - 'a'];
            }
            mp[res].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto vs : mp) {
            ans.push_back(vs.second);
        }
        return ans;
    }
};
// @lc code=end
