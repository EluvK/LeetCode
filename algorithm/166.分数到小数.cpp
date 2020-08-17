/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
using namespace std;

class mypair {
public:
    int first;
    int second;
    mypair(int f = -1, int s = -1) {
        first = f;
        second = s;
    };
    bool operator==(const mypair & other) const { return first == other.first && second == other.second; }
};

namespace std {
template <>
struct hash<mypair> {
    size_t operator()(const mypair & k) const { return k.first ^ k.second; }
};
}  // namespace std

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<mypair, size_t> loc;  // pair<div,mod>
        long nu = static_cast<long>(numerator);
        long de = static_cast<long>(denominator);
        string res;
        if (nu == 0)
            return "0";
        if ((nu < 0 && de > 0) || (nu > 0 && de < 0)) {
            nu = abs(nu);
            de = abs(de);
            res = "-";
        }
        if (nu < 0 && de < 0) {
            nu = -nu;
            de = -de;
        }
        long mod = nu % de;
        long div = nu / de;
        res = res + to_string(div);

        if (mod)
            res = res + ".";
        while (mod) {
            int append = 0;
            long new_numerator = mod * 10;
            while (new_numerator < de) {
                new_numerator *= 10;
                append++;
            }
            mod = new_numerator % de;
            div = new_numerator / de;
            if (loc.find(mypair(div, mod)) != loc.end()) {
                res = res + ")";
                res.insert(res.begin() + loc[mypair(div, mod)] - append, '(');

                break;
            }
            if (append) {
                for (int i = 0; i < append; ++i, res = res + "0")
                    ;
            }
            res = res + to_string(div);
            loc[mypair(div, mod)] = res.size() - 1;
        }
        return res;
    }
};
// @lc code=end
