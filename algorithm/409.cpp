class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52]={0};
        for(auto c:s){
            if(c-'a'>=0&&c-'a'<26) cnt[c-'a']++;
            else cnt[c-'A'+26]++;
        }
        int ans=0;
        bool flag=false;
        for(int i=0;i<52;++i){
            if(cnt[i]%2==0){
                ans+=cnt[i];
            }else{
                ans+=(cnt[i]-1);
                flag=true;
            }
        }
        return flag?ans+1:ans;
    }
};
