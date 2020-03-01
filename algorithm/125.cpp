class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();++i) if(isalpha(s[i])||isdigit(s[i])) ans+=toupper(s[i]);
        int len=ans.size();
        for(int i=0;i<=len/2;++i) if(ans[i]!=ans[len-i-1]) return false;
        return true;
    }
};
