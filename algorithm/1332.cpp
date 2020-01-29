class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        bool flag=true;
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]!=s[len-1-i]){
                flag=false;
                break;
            }
        }
        if(flag) return 1;
        else return 2;
    }
};
