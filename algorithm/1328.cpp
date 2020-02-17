class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool flag=false;
        string str=palindrome;
        for(int i=0;i<str.size();i++){
            if(str[i]!='a'){
                if(str.size()%2==1&&i==(str.size()/2)) continue;
                str[i]='a';
                flag=true;
                break;
            }
        }
        string v="";
        if(flag) return str;
        else{
            if(str.size()>1){
                str[str.size()-1]='b';
                return str;
            }
            else{
                return v;
            }
        }
    }
};
