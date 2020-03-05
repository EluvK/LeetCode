class Solution {
public:
    string compressString(string S) {
        string ans="";
        if(!S.size()) return ans;
        int i=1,cnt=1;
        while(i<S.size()){
            if(S[i]!=S[i-1]){
                ans+=S[i-1];
                ans+=to_string(cnt);
                cnt=1;
            }else{
                cnt++;
            }
            i++;
        }
        ans+=S[i-1];
        ans+=to_string(cnt);
        return ans.size()>=S.size()?S:ans;
    }
};
