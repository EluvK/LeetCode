/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
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
    int cmp(vector<string> const & v1, vector<string> const & v2) {
        int i = 0;
        for (; i < min(v1.size(), v2.size()); ++i) {
            if (atoi(v1[i].c_str()) > atoi(v2[i].c_str()))
                return 1;
            else if (atoi(v1[i].c_str()) < atoi(v2[i].c_str()))
                return -1;
        }
        if (v1.size() > v2.size()) {
            while (i < v1.size()) {
                if (atoi(v1[i].c_str()) > 0)
                    return 1;
                i++;
            }
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        split_string(version1, '.', v1);
        split_string(version2, '.', v2);
        if (v1.size() < v2.size())
            return -cmp(v2, v1);
        return cmp(v1, v2);
    }
};
// @lc code=end
