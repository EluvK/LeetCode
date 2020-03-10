class Solution {
public:
    string generateTheString(int n) {
        string ans="";
        if(n==0){
            return ans;
        }
        if(n==1){
            ans+="a";return ans;
        }
        if(n%2){
            ans+="ab";
            n-=2;
            while(n-->0) ans+="c";
        }
        else{
            ans+="a";
            n-=1;
            while(n-->0) ans+="c";
        }
        return ans;

    }
};
