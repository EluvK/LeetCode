/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int cal(int a, int b, int operator_num) {
        switch (operator_num) {
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return a / b;
        default:
            return -1;
        }
    }
    int evalRPN(vector<string> & tokens) {
        stack<int> nums;
        map<string, int> mp{{"+", 1}, {"-", 2}, {"*", 3}, {"/", 4}};
        for (auto str : tokens) {
            if (mp[str]) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(cal(a, b, mp[str]));
            } else {
                nums.push(atoi(str.c_str()));
            }
        }
        return nums.top();
    }
};
// @lc code=end
