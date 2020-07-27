/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int last = 9999, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int temp = mp[s[i]];
            if (temp > last)
                res = res - last * 2;
            res += temp;
            last = temp;
        }
        return res;
    }
};

// @lc code=end
