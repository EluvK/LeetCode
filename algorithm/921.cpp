class Solution {
public:
    int minAddToMakeValid(string S) {
        int len=S.size(),cnt=0,ans=0;
        for(int i=0;i<len;i++){
            if(cnt<0){
                ans-=cnt;
                cnt=0;
            }
            if(S[i]=='(') cnt++;
            if(S[i]==')') cnt--;
        }
        return ans+abs(cnt);
    }
};
