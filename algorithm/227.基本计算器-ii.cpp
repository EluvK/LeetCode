/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
using namespace std;
class Solution {
public:
    /*
        map<string, int> op{{"+", 1}, {"-", 2}, {"*", 3}, {"/", 4}};
        map<string, int> pri{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};
        string trimspace(string s) {
            string res;
            for (auto c : s) {
                if (isspace(c))
                    continue;
                res = res + c;
            }
            return res;
        }

        void split_num(string s, vector<string> & v) {
            string tmp;
            for (auto c : s) {
                if (isdigit(c))
                    tmp = tmp + c;
                else {
                    v.push_back(tmp);
                    tmp.clear();
                    v.push_back(std::string{c});
                }
            }
            if (!tmp.empty())
                v.push_back(tmp);
        }
    */
    int calculate(string s) {
        long res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                case '+':
                    curRes += num;
                    break;
                case '-':
                    curRes -= num;
                    break;
                case '*':
                    curRes *= num;
                    break;
                case '/':
                    curRes /= num;
                    break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
// @lc code=end
