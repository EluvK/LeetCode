/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int maximumGap(vector<int> & nums) {
        if (nums.size() < 2)
            return 0;
        set<int> nst{nums.begin(), nums.end()};
        nums = vector<int>(nst.begin(), nst.end());
        int min_num = INT_MAX, max_num = INT_MIN;
        for (auto c : nums) {
            min_num = min(min_num, c);
            max_num = max(max_num, c);
        }
        if (min_num == max_num)
            return 0;
        int gap = (max_num - min_num) / nums.size();
        vector<pair<int, int>> bucket;
        int st = min_num;
        while (st <= max_num) {
            bucket.push_back(make_pair(st + gap, st));
            st += gap;
        }
        for (auto c : nums) {
            int index_ = (c - min_num) / gap;
            bucket[index_] = make_pair(min(bucket[index_].first, c), max(bucket[index_].second, c));
        }
        st = 0;
        int ed = 1, res = 0;
        while (st != bucket.size() - 1) {
            while (ed != bucket.size() && bucket[ed].second < bucket[ed].first)
                ed++;
            if (ed == bucket.size())
                break;
            res = max(bucket[ed].first - bucket[st].second, res);
            st = ed;
            ed++;
        }
        return res;
    }
};
// @lc code=end
