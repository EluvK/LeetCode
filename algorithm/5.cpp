#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LPS_dp {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int ans = 1;
        int ans_start = 0;
        vector<vector<int>>  dp(len, vector<int>(len));
        for(int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if(i < len - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
                ans_start = i;
            }
        }
        for(int L = 3; L <= len; L++) {
            for(int i = 0; i + L - 1 < len; i++) {
                int j = i + L - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    ans = L;
                    ans_start = i;
                }
            }
        }
        return s.substr(ans_start, ans);
    }
};


class LPS_Manacher {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for(auto c : s) {
            t += c;
            t += "#";
        }

        vector<int> p(t.size(), 0);

        int mx = 0, c = 0, resL = 0, resC = 0;

        for(int i = 1; i < t.size(); i++) {

            p[i] = mx > i ? min(p[2 * c - i], mx - i) : 1;

            while(t[i + p[i]] == t[i - p[i]])
                p[i]++;

            if(mx < i + p[i]) {
                c = i;
                mx = i + p[i];
            }
            if(resL < p[i]) {
                resL = p[i];
                resC = i;
            }
        }
        return s.substr((resC - resL) / 2, resL - 1);

    }
};

int main() {
    string str = "abcbabcb";
    LPS_Manacher s;
    cout << s.longestPalindrome(str);
}
