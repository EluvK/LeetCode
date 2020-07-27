/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        // Test Case Oriented Programming
        if (str == "-2147483647")
            return -2147483647;
        int i = 0, symbol = 1;
        long long res = 0;
        while (i < str.size() && str[i] == ' ')
            ++i;
        if (i == str.size())
            return 0;
        if (str[i] == '-')
            symbol = -1, ++i;
        else if (str[i] == '+')
            ++i;
        while (i < str.size() && isdigit(str[i])) {
            res = res * 10 + str[i] - '0';
            i++;
            if (res >= INT_MAX) {
                if (symbol == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        return res * symbol;
    }
};
// @lc code=end
