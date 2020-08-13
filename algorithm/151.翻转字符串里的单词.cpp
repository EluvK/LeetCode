/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int split_string(const std::string & input, const char split_char, std::vector<std::string> & values) {
        if (input.empty())
            return 0;

        std::size_t begin_pos = 0;
        std::size_t pos_of_split = input.find_first_of(split_char, begin_pos);
        while (pos_of_split != std::string::npos) {
            if (pos_of_split != begin_pos)
                values.push_back(input.substr(begin_pos, pos_of_split - begin_pos));
            begin_pos = pos_of_split + 1;
            pos_of_split = input.find_first_of(split_char, begin_pos);
            if (pos_of_split == std::string::npos) {
                if (begin_pos < input.size()) {
                    values.push_back(input.substr(begin_pos));
                }
            }
        }
        if (values.empty())
            values.push_back(input);

        return (int)values.size();
    }
    std::string trim_string(std::string input) {
        string output{};
        for (int i = 0; i < input.size();) {
            output.push_back(input[i++]);
            if (input[i - 1] == ' ') {
                while (i < input.size() && input[i] == ' ') {
                    i++;
                }
            }
        }
        return output;
    }
    string reverseWords(string s) {
        vector<string> val;
        s = trim_string(s);
        if (s == " ")
            return {};
        split_string(s, ' ', val);
        string ans;
        reverse(val.begin(), val.end());
        for (auto str : val) {
            ans = ans + str + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};
// @lc code=end
