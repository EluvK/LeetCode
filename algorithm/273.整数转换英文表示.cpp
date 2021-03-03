/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
public:
    string to19[19] = {"One",
                       "Two",
                       "Three",
                       "Four",
                       "Five",
                       "Six",
                       "Seven",
                       "Eight",
                       "Nine",
                       "Ten",
                       "Eleven",
                       "Twelve",
                       "Thirteen",
                       "Fourteen",
                       "Fifteen",
                       "Sixteen",
                       "Seventeen",
                       "Eighteen",
                       "Nineteen"};
    string tens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string lions[3] = {"Thousand", "Million", "Billion"};

    long powint(int n, int e) {
        long res = 1;
        while (e--) {
            res *= n;
        }
        return res;
    }
    string work(int num) {
        if (num == 0)
            return "";
        if (num < 20)
            return to19[num - 1];
        if (num < 100)
            return tens[num / 10 - 2] + work(num % 10);
        if (num < 1000)
            return to19[num / 100 - 1] + "Hundred" + work(num % 100);
        for (auto index = 0; index < 4; ++index) {
            if (num < powint(1000, index + 1)) {
                return work(num / (powint(1000, index))) + lions[index - 1] + work(num % (powint(1000, index)));
            }
        }
        return "wrong";
    }
    string add_space(std::string input) {
        string res = "";
        for (auto index = 0; index < input.size(); ++index) {
            res.push_back(input[index]);
            if (index + 1 < input.size() && isupper(input[index + 1]))
                res.push_back(' ');
        }
        return res;
    }
    string numberToWords(int num) {
        // std::cout << work(12) << std::endl;
        // std::cout << work(123) << std::endl;
        // std::cout << work(1234) << std::endl;
        // std::cout << work(12345) << std::endl;
        // std::cout << work(123456) << std::endl;
        // std::cout << work(1234567) << std::endl;
        // std::cout << work(12345678) << std::endl;
        // std::cout << work(123456789) << std::endl;
        return num ? add_space(work(num)) : "Zero";
    }
};
// @lc code=end
