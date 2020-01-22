class Solution {
public:
    bool isPalindrome(int x) {
        string rx=to_string(x);
        reverse(rx.begin(),rx.end());
        return to_string(x)==rx;
    }
};
