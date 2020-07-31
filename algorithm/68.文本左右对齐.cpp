/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
using namespace std;
class Solution {
public:
    string range_row(vector<string> const & row_strs, int maxWidth) {
        string ans{};
        int sumlength = 0;
        for (auto str : row_strs)
            sumlength += str.size();
        int all_blankspace = maxWidth - sumlength;
        int all_gap = row_strs.size() - 1;

        if (row_strs.size() == 1) {
            ans = ans + row_strs[0];
            for (int i = 0; i < maxWidth - sumlength; ++i) {
                ans = ans + " ";
            }
            return ans;
        }
        if (row_strs.size() == 2) {
            ans = ans + row_strs[0];
            for (int i = 0; i < maxWidth - sumlength; ++i) {
                ans = ans + " ";
            }
            ans = ans + row_strs[1];
            return ans;
        }

        for (int i = 0; i < row_strs.size(); ++i) {
            auto str = row_strs[i];
            // for (auto str : row_strs) {
            ans = ans + str;
            if (i == row_strs.size() - 1)
                break;
            int blank_size = (all_blankspace + all_gap - 1) / all_gap;
            for (int j = 0; j < blank_size; ++j) {
                ans = ans + " ";
            }
            all_blankspace -= blank_size;
            all_gap--;
        }
        return ans;
    }
    void adjust_last_row(string & str, int maxWidth) {
        for (int i = 0; i < str.size() - 1; ++i) {
            if (str[i] == ' ' && str[i + 1] == ' ') {
                str.erase(str.begin() + i);
                --i;
            }
        }
        int len = str.size();
        for (int i = 0; i < maxWidth - len; ++i) {
            str = str + " ";
            // cout << endl << i;
        }
        return;
    }
    vector<string> fullJustify(vector<string> & words, int maxWidth) {
        vector<string> tmp;
        vector<string> ans;
        int sum_size = 0;
        for (int i = 0; i < words.size();) {
            string w = words[i];
            if (sum_size + w.size() + 1 <= maxWidth || sum_size + w.size() == maxWidth) {
                sum_size = sum_size + w.size() + 1;
                tmp.push_back(w);
                ++i;
            } else {
                ans.push_back(range_row(tmp, maxWidth));
                tmp.clear();
                sum_size = 0;
            }
        }
        if (!tmp.empty())
            ans.push_back(range_row(tmp, maxWidth));
        adjust_last_row(ans.back(), maxWidth);
        return ans;
    }
};
// @lc code=end
