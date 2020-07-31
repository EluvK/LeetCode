/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
using namespace std;
class Solution {
public:
    void split_string(string src, char pattren, vector<string> & res) {
        string tmp{};
        for (auto c : src) {
            if (c == pattren) {
                res.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        res.push_back(tmp);
        return;
    }
    string simplifyPath(string path) {
        vector<string> splited_v;
        vector<string> res_v;
        split_string(path, '/', splited_v);
        for (auto str : splited_v) {
            if (str.empty() || str == ".")
                continue;
            if (str == "..") {
                if (!res_v.empty())
                    res_v.pop_back();
            } else {
                res_v.push_back(str);
            }
        }
        string res{};
        for (auto rev : res_v) {
            res = res + ("/" + rev);
        }
        if (res.empty())
            return "/";
        return res;
    }
};
// @lc code=end
