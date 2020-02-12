class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26]={0};
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            if(cnt[t[i]-'a']>0) cnt[t[i]-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=cnt[i];
        }
        return ans;
    }
};
